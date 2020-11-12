#include "Sync_Service.h"

Sync_Service::Sync_Service(Data_Base &data_base, Queue_Api &queue) : data_base(data_base), queue(queue) {}

bool Sync_Service::listen() {
    Message mes;
    std::vector<Message> mess;
    data_base.update(mes, mess);
    return false;
}

bool Sync_Service::notify() {
    return false;
}


