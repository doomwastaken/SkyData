#ifndef PROJECT_MESSAGEUPDATER_H
#define PROJECT_MESSAGEUPDATER_H
#include <iostream>
#include "Message.h"
#include "queue"
#include <memory>
#include "ClientSender.h"
#include <mutex>


class MessageUpdater {
private:

    std::mutex mtx;
public:
    static std::mutex mtx_stat;
    ClientSender sender;
    MessageUpdater();
public:
    static std::queue<std::shared_ptr<Message>> processed_messages;
    void to_client_send();
    static void push(const std::shared_ptr<Message>& message);
};

#endif //PROJECT_MESSAGEUPDATER_H
