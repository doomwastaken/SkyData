#ifndef PROJECT_MESSAGEUPDATER_H
#define PROJECT_MESSAGEUPDATER_H
#include <iostream>
#include "Message.h"
#include "vector"


class MessageUpdater {
    std::vector<Message> processed_messages;
    //Client_Sender sender;
public:
    void to_client_send();
    void push();
};

#endif //PROJECT_MESSAGEUPDATER_H
