#include "RPCServer.h"
RPCServer::RPCServer(void){
    this->variables = nullptr;
}

bool RPCServer::Init(int _tableWidth = 32, int _poolSize = 4){
    this->variables = new VarTable(_tableWidth);
    // Allocate the thread pool here.
    return true;
}