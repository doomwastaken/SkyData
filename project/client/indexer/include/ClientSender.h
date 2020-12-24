#ifndef PROJECT_CLIENTSENDER_H
#define PROJECT_CLIENTSENDER_H

#include <queue>

#include "CloudStorageWorker.h"
#include "InternalDataBaseWorker.h"
#include "Message.h"
#include "ClientsConnection.h"

class ClientSender {
public:
    ClientSender() = default;

    enum event_BD {
        ONLY_SQL,
        BOTH
    };

    int send(std::shared_ptr<Message> &message, ClientsConnection &cl_con,
             ClientToStorageConnection &storage_conn, event_BD event_bd, std::string &proverka);

private:
    InternalDataBaseWorker m_internal_db;
    CloudStorageWorker m_cloud_storage;
};

#endif //PROJECT_CLIENTSENDER_H