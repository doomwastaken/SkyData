#ifndef PROJECT_CLOUD_STORAGE_WORKER_H
#define PROJECT_CLOUD_STORAGE_WORKER_H

#include "Cloud_Storage_DB.h"
#include "Message.h"

class Cloud_Storage_Worker {
public:
    explicit Cloud_Storage_Worker() = default;
    int send_to_cloud(Message& message);

private:
    Cloud_Storage *cloud_storage;
};

#endif //PROJECT_CLOUD_STORAGE_WORKER_H
