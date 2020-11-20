#ifndef PROJECT_QUEUE_H
#define PROJECT_QUEUE_H

#include <cstdlib>
#include "Message.h"

class Queue {
private:
    size_t size;
public:
    virtual void push_to_queue(Message message) = 0;
    virtual Message pop_from_queue() = 0;
    bool is_empty();
};


#endif //PROJECT_QUEUE_H
