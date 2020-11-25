#ifndef _RPCSERVER_H_
#define _RPCSERVER_H_
#include <err.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include "VarTable.h"
#include "SmartArray.h"

// Create Mutex lock for variable table.
class RPCServer{
    private:
    VarTable* variables;
    char sns[16];
    int portNo;
    int sock;
    void validArgCount(int) const;
    void getProtocolData(char*);
    void getSock(void);
    public:
    RPCServer(void);
    bool Config(int, int);
    bool Init(int, char**);
    bool VarLookup(const std::string&, int64_t&);
    bool VarAssign(const std::string&, int64_t&);
    bool VarLoad(const std::string&);
    bool VarDump(const std::string&);
};
#endif
