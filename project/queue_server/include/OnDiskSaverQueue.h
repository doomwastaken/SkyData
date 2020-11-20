#ifndef PROJECT_ONDISKSAVERQUEUE_H
#define PROJECT_ONDISKSAVERQUEUE_H

#include "Queue.h"

class OnDiskSaverQueue : public Queue {
    std::string queue_directory;
    size_t start_index;
    size_t end_index;

public:
    OnDiskSaverQueue(std::string dir);
    void push_to_queue(Message message) override;
    Message pop_from_queue() override;
};


#endif //PROJECT_ONDISKSAVERQUEUE_H
