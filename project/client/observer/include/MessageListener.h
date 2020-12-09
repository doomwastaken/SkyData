#ifndef PROJECT_MESSAGELISTENER_H
#define PROJECT_MESSAGELISTENER_H
#include "iostream"
#include "Message.h"
#include "EventEditor.h"
#include "ClientCommand.h"

class MessageListener : public EventEditor{
 //   ClientCommand client_command;
    void to_listen_message();


public:
    int event() override;
};

#endif //PROJECT_MESSAGELISTENER_H
