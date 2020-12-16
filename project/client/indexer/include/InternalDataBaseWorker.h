#ifndef PROJECT_INTERNALDATABASEWORKER_H
#define PROJECT_INTERNALDATABASEWORKER_H

#include <vector>
#include <memory>
#include "SQLite.h"
#include "Message.h"

class InternalDataBaseWorker {
public:
    InternalDataBaseWorker() = default;
    int send_meta_data(std::shared_ptr<Message> &message);

private:
    std::shared_ptr<InternalDataBase> data_base;
};

#endif //PROJECT_INTERNALDATABASEWORKER_H
