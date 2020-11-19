#ifndef PROJECT_CLIENTSENDER_H
#define PROJECT_CLIENTSENDER_H

#include "CloudStorageWorker.h"
#include "InternalDataBaseWorker.h"
#include "Message.h"
#include "ClientCommand.h"

class ClientSender {
public:
    ClientSender() = default;

    int send(Message &message);

private:
    InternalDataBaseWorker internal_db;
    CloudStorageWorker cloud_storage;
    ClientCommand *commander;
};

#endif //PROJECT_CLIENTSENDER_H
