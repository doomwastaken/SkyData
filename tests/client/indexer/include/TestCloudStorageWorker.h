#ifndef PROJECT_TESTCLOUDSTORAGEWORKER_H
#define PROJECT_TESTCLOUDSTORAGEWORKER_H

#include <Message.h>
#include "gmock/gmock.h"

class MockTestCloudStorageWorker {
public:
    MOCK_METHOD(int, send_to_cloud, (Message& message), ());
};

template<class Type>
class MockCloudStorageWorker {
public:
    explicit MockCloudStorageWorker(Type* val) : value(val) { }

    void send(Message &message) {
        value->send_to_cloud(message);
    }

private:
    Type* value;
};
#endif //PROJECT_TESTCLOUDSTORAGEWORKER_H
