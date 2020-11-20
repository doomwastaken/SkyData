#ifndef QUEUE_TESTS_MASTER_MOCK_H
#define QUEUE_TESTS_MASTER_MOCK_H

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Master.h"

#include <vector>
#include <string>

class Mock_Master {
public:
    explicit Mock_Master(int listener, int timeout = 100) :
            timeout(timeout),
            listener(listener)
    {};
    MOCK_METHOD(void, run_server, (), ());
    MOCK_METHOD(void, create_connection, (Socket socket,  EventLoop &loop), ());

private:
    int timeout;
    int listener;
};

// Non-virtual methods. Static Polymorphism!
template<class q_master>
class User {
public:
    User(q_master* master) : _master(master) { }

    void run_server() {
        _master->run_server();
    }

    void create_connection(Socket socket,  EventLoop &loop) {
        _master->create_connection(socket, loop);
    }

private:
    q_master* _master;
};

#endif //QUEUE_TESTS_MASTER_MOCK_H
