#ifndef PROJECT_MESSAGE_LISTENER_H
#define PROJECT_MESSAGE_LISTENER_H
#include "iostream"
#include "messages.h"

class Message_Listener {
    Message message;
    void create_message();

public:
    void to_listen_message();
};

#endif //PROJECT_MESSAGE_LISTENER_H
