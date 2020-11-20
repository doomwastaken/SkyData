#include "StdQueue.h"

void StdQueue::push_to_queue(Message message) {
    messages.push(message);
    size++;
}

Message StdQueue::pop_from_queue() {
    Message msg = messages.front();
    messages.pop();
    size--;
    return msg;
}
