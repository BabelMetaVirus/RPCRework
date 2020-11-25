#include "RPCServer.h"
void RPCServer::validArgCount(int _argc) const{
    if(_argc < 2){
        err(EXIT_FAILURE, "Not enough arguments.\n");
        exit(-1);
    }
    else if(_argc > 2){
        err(EXIT_FAILURE, "Too many arguments.\n");
        exit(-1);
    }
}
// IP Array needs to be size 16.
void RPCServer::getProtocolData(char *_arg){
    char* tmp = strchr(_arg,':');
    if(!tmp){
        printf("No port specified.\n");
        exit(1);
    }
    this->portNo = std::stoi(tmp + 1);
    int dist = tmp - _arg;
    for(int i = 0; i < dist; i++){
        this->sns[i] = _arg[i];
    }
    this->sns[dist] = '\0';
}
void RPCServer::getSock(void){
    // given socket code from pages resouce
    struct hostent *hent = gethostbyname(this->sns /* eg "localhost" */);
    struct sockaddr_in addr;
    memcpy(&addr.sin_addr.s_addr, hent->h_addr, hent->h_length);
    addr.sin_port = htons(this->portNo);
    addr.sin_family = AF_INET;

    this->sock = socket(AF_INET, SOCK_STREAM, 0);
    if (this->sock < 0)
    {
        perror("Server could not be created\n");
        exit(-1);
    }

    int enable = 1;
    int sso = setsockopt(this->sock, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable));
    if (sso < 0)
    {
        perror("Socket control failed\n");
        close(this->sock);
        exit(-1);
    }

    int binds = bind(this->sock, (struct sockaddr *)&addr, sizeof(addr));
    if (binds < 0)
    {
        perror("Bind failed\n");
        close(this->sock);
        exit(-1);
    }

    // code used from jim's post on piazza
    if (listen(this->sock,128) != 0) err(2,"unable to listen");

}

RPCServer::RPCServer(void){
    this->variables = nullptr;
}

bool RPCServer::Config(int _tableWidth = 32, int _poolSize = 4){
    this->variables = new VarTable(_tableWidth);
    // Allocate the thread pool here.
    return true;
}

bool RPCServer::Init(int _argc, char** _argv){
    // TODO: Add code for hash table width and thread pool size processing.
    this->getProtocolData(_argv[1]);
    this->getSock();
    return true;
}