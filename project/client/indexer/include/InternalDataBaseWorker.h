#ifndef PROJECT_INTERNALDATABASEWORKER_H
#define PROJECT_INTERNALDATABASEWORKER_H

#include <vector>
#include <memory>
#include "PostgressInternalDB.h"
#include "Message.h"

class InternalDataBaseWorker {
public:
    explicit InternalDataBaseWorker();
    int send_meta_data(std::shared_ptr<Message> &message);

private:
    std::unique_ptr<InternalDataBase> data_base;
};

#endif //PROJECT_INTERNALDATABASEWORKER_H
