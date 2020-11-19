#ifndef PROJECT_TESTCLOUDSTORAGEWORKER_H
#define PROJECT_TESTCLOUDSTORAGEWORKER_H

#include <Message.h>
#include "gmock/gmock.h"

class MockTestClientSender {
public:
    MOCK_METHOD(int, send_to_cloud, (Message& message), ());
};

template<class Type>
class MockClientSender {
public:
    explicit MockClientSender(Type* val) : value(val) { }

    void get_connection(Message &message) {
        value->send_to_cloud(message);
    }

private:
    Type* value;
};
#endif //PROJECT_TESTCLOUDSTORAGEWORKER_H
