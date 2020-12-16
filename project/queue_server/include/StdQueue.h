#ifndef PROJECT_STDQUEUE_H
#define PROJECT_STDQUEUE_H


#include "Queue.h"
#include <queue>

class StdQueue : public Queue {
private:
    std::queue<std::string> messages;
public:
    void push_to_queue(std::string message) override;
    std::string pop_from_queue() override;
};


#endif //PROJECT_STDQUEUE_H
