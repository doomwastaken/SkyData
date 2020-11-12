#ifndef PROJECT_SYNC_SERVICE_H
#define PROJECT_SYNC_SERVICE_H

#include <vector>

#include "Message.h"
#include "Data_Base.h"

//класс заглушка для тестов, позже будет добавлен класс который делает мой сокомандник
class Queue_Api {
    void push_to_queue(Message &message);

    Message pop_from_queue();

};

class Sync_Service {
public:
    explicit Sync_Service(Data_Base &data_base, Queue_Api &queue);

    bool listen();

private:
    bool notify();

    std::vector<Message> messages;
    Data_Base &data_base;
    Queue_Api &queue;
};


#endif //PROJECT_SYNC_SERVICE_H
