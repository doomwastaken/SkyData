#ifndef PROJECT_MESSAGELISTENER_H
#define PROJECT_MESSAGELISTENER_H
#include "iostream"
#include "messages.h"
#include "EventEditor.h"

class MessageListener : public EventEditor{
    Message message;
    Message to_listen_message();


public:
    int event() override;
};

#endif //PROJECT_MESSAGELISTENER_H
