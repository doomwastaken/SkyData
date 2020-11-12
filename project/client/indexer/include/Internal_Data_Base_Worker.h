#ifndef PROJECT_INTERNAL_DATA_BASE_WORKER_H
#define PROJECT_INTERNAL_DATA_BASE_WORKER_H

#include "Postgress_Internal_DB.h"
#include "Message.h"

class Internal_Data_Base_Worker {
public:
    explicit Internal_Data_Base_Worker();
    int send_to_data_base(Message& message);

private:
    Postgress_Internal_DB data_base{};
};

#endif //PROJECT_INTERNAL_DATA_BASE_WORKER_H
