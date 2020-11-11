#ifndef PROJECT_CLIENT_SENDER_H
#define PROJECT_CLIENT_SENDER_H

#include "Cloud_Storage_Worker.h"
#include "Internal_Data_Base_Worker.h"
#include "Message.h"

class Client_Sender {
public:
    Client_Sender() = default;
    int send(Message& message, int key);

private:
    Internal_Data_Base_Worker internal_db;
    Cloud_Storage_Worker cloud_storage;
};

#endif //PROJECT_CLIENT_SENDER_H
