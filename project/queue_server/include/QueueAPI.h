#ifndef PROJECT_QUEUEAPI_H
#define PROJECT_QUEUEAPI_H

#include <vector>
#include <string>
#include "Message.h"

enum {
    CONNECTION_SUCCESS,
    CONNECTION_FAILURE,
};

class Queue_API {
public:
    void establish_connection();
    void break_connection();
    void send_message(Message &msg);
    Message receive_message();
};


#endif //PROJECT_QUEUEAPI_H
