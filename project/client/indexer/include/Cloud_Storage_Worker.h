#ifndef PROJECT_CLOUD_STORAGE_WORKER_H
#define PROJECT_CLOUD_STORAGE_WORKER_H

#include "Cloud_Storage.h"
#include "Message.h"

class Cloud_Storage_Worker {
public:
    explicit Cloud_Storage_Worker(Message message);
    int send_to_cloud(Message& message);

private:
    Cloud_Storage m_cloud_storage{};
    Message m_message;
};

#endif //PROJECT_CLOUD_STORAGE_WORKER_H
