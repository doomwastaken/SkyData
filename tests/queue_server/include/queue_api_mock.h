#ifndef PROJECT_QUEUE_API_MOCK_H
#define PROJECT_QUEUE_API_MOCK_H

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "QueueAPI.h"

#include <vector>
#include <string>

class Mock_Queue_API {
public:
    MOCK_METHOD(int, establish_connection, (), ());
    MOCK_METHOD(int, break_connection, (), ());
    MOCK_METHOD(int, send_message, (Message), ());
    MOCK_METHOD(Message, receive_message, (), ());
};

// Non-virtual methods. Static Polymorphism!
template<class q_api>
class User {
public:
    User(q_api* api) : api_(api) { }

    void get_connection() {
        api_->establish_connection();
    }

    void quit_connection() {
        api_->break_connection();
    }

    void try_to_send_message(Message msg) {
        api_->send_message(msg);
    }

    void try_to_receive_message() {
        api_->receive_message();
    }

private:
    q_api* api_;
};

#endif //PROJECT_QUEUE_API_MOCK_H
