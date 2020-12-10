#ifndef PROJECT_CLIENTSENDER_H
#define PROJECT_CLIENTSENDER_H

#include <queue>

#include "CloudStorageWorker.h"
#include "InternalDataBaseWorker.h"
#include "Message.h"

class ClientSender {
public:
    ClientSender() = default;

    int send(std::shared_ptr<Message> &message);

private:
    InternalDataBaseWorker m_internal_db;
    CloudStorageWorker m_cloud_storage;
};

#endif //PROJECT_CLIENTSENDER_H