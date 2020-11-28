#ifndef PROJECT_SYNCSERVICEAPI_H
#define PROJECT_SYNCSERVICEAPI_H

#include "Message.h"

class SyncServiceAPI {
    SyncServiceAPI() = default;

    void connect();

    void disconnect();

    int send_message(Message message);

//    Message &receive_message();

};


#endif //PROJECT_SYNCSERVICEAPI_H
