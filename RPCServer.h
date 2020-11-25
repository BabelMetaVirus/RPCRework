#ifndef _RPCSERVER_H_
#define _RPCSERVER_H_
#include "VarTable.h"
// Create Mutex lock for variable table.
class RPCServer{
    private:
    VarTable* variables;
    public:
    RPCServer(void);
    bool Init(int, int);
    bool VarLookup(const std::string&, int64_t&);
    bool VarAssign(const std::string&, int64_t&);
    bool VarLoad(const std::string&);
    bool VarDump(const std::string&);
};
#endif
