#include "OnDiskSaverQueue.h"

#include <utility>

void OnDiskSaverQueue::push_to_queue(Message message) {

}

Message OnDiskSaverQueue::pop_from_queue() {
    return Message();
}

OnDiskSaverQueue::OnDiskSaverQueue(std::string dir) : queue_directory(std::move(dir)), start_index(0), end_index(0) { }
