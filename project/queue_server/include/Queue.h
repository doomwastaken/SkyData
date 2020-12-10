#ifndef PROJECT_QUEUE_H
#define PROJECT_QUEUE_H

#include <cstdlib>
#include <mutex>
#include "Message.h"

class Queue {
protected:
    size_t size;
    std::mutex mtx;
public:
    virtual void push_to_queue(std::string message) = 0;
    virtual std::string pop_from_queue() = 0;
    size_t get_size() const { return size; };
    bool is_empty() const { return size == 0; }
};


#endif //PROJECT_QUEUE_H
