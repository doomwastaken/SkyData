#include "StdQueue.h"

void StdQueue::push_to_queue(std::string message) {
    messages.push(message);
    size++;
}

std::string StdQueue::pop_from_queue() {
    std::string msg = messages.front();
    messages.pop();
    size--;
    return msg;
}
