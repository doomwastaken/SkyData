#ifndef PROJECT_CLOUDSTORAGEWORKER_H
#define PROJECT_CLOUDSTORAGEWORKER_H

#include <vector>
#include <memory>
#include "CloudStorageDB.h"
#include "Message.h"

class CloudStorageWorker {
public:
    explicit CloudStorageWorker() = default;
    int send_to_cloud(std::shared_ptr<Message> &message);

private:
    CloudStorage *cloud_storage;
    std::vector<Message> *messages;
};

#endif //PROJECT_CLOUDSTORAGEWORKER_H