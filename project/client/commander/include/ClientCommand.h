#ifndef PROJECT_CLIENTCOMMAND_H
#define PROJECT_CLIENTCOMMAND_H

#include "ClientSocked.h"

class ClientCommand {
public:
    ClientSocked client_socked;
    virtual ~ClientCommand() = default;

private:
    virtual int command() = 0;
};

#endif //PROJECT_CLIENTCOMMAND_H
