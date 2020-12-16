#ifndef PROJECT_MESSAGEUPDATER_H
#define PROJECT_MESSAGEUPDATER_H
#include <iostream>
#include "Message.h"
#include "queue"
#include <memory>
#include <mutex>
#include "ClientSender.h"
#include "ClientToStorageConnection.h"


class MessageUpdater {
private:

    std::mutex mtx;
public:
    static std::mutex mtx_stat;
    ClientSender sender;
    MessageUpdater();
public:
    static std::queue<std::pair<std::shared_ptr<Message>, bool>> processed_messages;
    void to_client_send(ClientsConnection &cl_con, ClientToStorageConnection &cl_to_storage);
    static void push(const std::shared_ptr<Message>& message, bool is_from_queue = false);
};

#endif //PROJECT_MESSAGEUPDATER_H
