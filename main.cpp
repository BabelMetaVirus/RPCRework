#include <iostream>
#include <string>
#include "string.h"
int main() {
    std::string tmp = "127.0.0.1:5600";
    char val[32];
    char buf[32];
    memset(buf,0,32);
    strcpy(val, tmp.c_str());
    char* offset = strchr(val, ':');
    *offset = '\0';
    int portAddr = std::stoi(offset + 1);
    for(int i = 0; i < 32; i++){
        std::cout << val[i];
    }
    std::cout << std::endl;
    std::cout << "Test Value: " << strlen(buf) << std::endl;
    std::cout << "Offset: " << offset - val << std::endl;
    std::cout << "Value: " << val << std::endl;
    std::cout << "Port: " << portAddr << std::endl;
  std::cout << "Hello World!\n";
}