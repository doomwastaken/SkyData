#ifndef SERV_EVENTLOOP_H
#define SERV_EVENTLOOP_H

#include <vector>
#include <queue>
#include <mutex>
#include <functional>
#include <memory>

#include "Event.h"
#include "Socket.h"
#include "Message.h"

class EventLoop {
private:
    std::vector<Event> m_clients_want_work;
    std::vector<Event> m_clients_have_work;
    std::shared_ptr<std::mutex> m_have_work_mutex;
    std::shared_ptr<std::mutex> m_want_work_mutex;

    EventLoop() = default;

    void manage_connections();

public:
    static EventLoop &eventLoop() {
        static EventLoop ev;
        return ev;
    }

    void async_read(Socket, Message, std::function<void(int)> cb);

    void async_write(Socket, Message, std::function<void(int)> cb);

    void delete_client();
};


#endif //SERV_EVENTLOOP_H
