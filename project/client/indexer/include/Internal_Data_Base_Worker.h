#ifndef PROJECT_INTERNAL_DATA_BASE_WORKER_H
#define PROJECT_INTERNAL_DATA_BASE_WORKER_H

#include "Internal_Data_Base.h"
#include "Message.h"

class Internal_Data_Base_Worker {
public:
    explicit Internal_Data_Base_Worker(Message &message);
    int send_to_data_base(Message& message);

private:
    Internal_Data_Base data_base{};
    Message message;
};

#endif //PROJECT_INTERNAL_DATA_BASE_WORKER_H
