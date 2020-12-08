#ifndef PROJECT_MESSAGELISTENER_H
#define PROJECT_MESSAGELISTENER_H
#include "iostream"
#include "Message.h"
#include "EventListen.h"

class MessageListener : public EventListen{
    Message message;
    Message to_listen_message();


public:
    int event() override;
};

#endif //PROJECT_MESSAGELISTENER_H
