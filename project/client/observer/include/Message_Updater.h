#ifndef PROJECT_MESSAGE_UPDATER_H
#define PROJECT_MESSAGE_UPDATER_H
#include <iostream>
#include "messages.h"
#include "Message_Listener.h"

class Message_Updater {
    Message_Listener listener;
    //Client_Sender sender;
public:
    void to_client_send();
};

#endif //PROJECT_MESSAGE_UPDATER_H
