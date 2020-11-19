#ifndef PROJECT_TESTINTERNALDATABASE_H
#define PROJECT_TESTINTERNALDATABASE_H

#include <Message.h>
#include "gmock/gmock.h"

class MockTestInternal {
public:
    MOCK_METHOD(int, send_meta_data, (Message& message), ());
};

template<class Type>
class MockInternal {
public:
    explicit MockInternal(Type* val) : value(val) { }

    void send_meta(Message &message) {
        value->send_meta_data(message);
    }

private:
    Type* value;
};

#endif //PROJECT_TESTINTERNALDATABASE_H
