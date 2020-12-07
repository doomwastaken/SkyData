#ifndef PROJECT_INTERNALDATABASEWORKER_H
#define PROJECT_INTERNALDATABASEWORKER_H

#include <vector>
#include "SQLite.h"
#include "Message.h"

class InternalDataBaseWorker {
public:
    explicit InternalDataBaseWorker();
    int send_meta_data(Message& message);

private:
    InternalDataBase *data_base;
    std::vector<Message> *messages;
};

#endif //PROJECT_INTERNALDATABASEWORKER_H
