#ifndef QUEUE_TESTS_EVENT_LOOP_MOCK_H
#define QUEUE_TESTS_EVENT_LOOP_MOCK_H

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Master.h"

#include <vector>
#include <string>

class Mock_Event_Loop {
private:
    Mock_Event_Loop() = default;
    std::vector<Event> m_clients_want_work;
    std::vector<Event> m_clients_have_work;
    std::shared_ptr<std::mutex> m_have_work_mutex;
    std::shared_ptr<std::mutex> m_want_work_mutex;
public:
    static Mock_Event_Loop &eventLoop() {
        static Mock_Event_Loop ev;
        return ev;
    }

    MOCK_METHOD(void, async_read, (Socket, Message, std::function<void(int)> cb), ());
    MOCK_METHOD(void, async_write, (Socket, Message, std::function<void(int)> cb), ());
};

// Non-virtual methods. Static Polymorphism!
template<class q_loop>
class User {
public:
    User(q_loop* loop) : loop(loop) { }

    void async_read(Socket s, Message m, std::function<void(int)> cb) {
        loop->async_read(s, m, cb);
    }

    void async_write(Socket s, Message m, std::function<void(int)> cb) {
        loop->async_read(s, m, cb);
    }

private:
    q_loop* loop;
};

#endif //QUEUE_TESTS_EVENT_LOOP_MOCK_H
