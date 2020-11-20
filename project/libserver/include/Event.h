#ifndef SERV_EVENT_H
#define SERV_EVENT_H

#include <vector>
#include <queue>
#include <mutex>
#include <functional>

#include "Socket.h"
#include "Message.h"

struct Event {
    explicit Event(Socket client, Message &message) : client(client), buffer(message) {}

    Socket client;

    std::function<void(int)> callback;

    std::reference_wrapper<Message> buffer;
};

#endif //SERV_EVENT_H
