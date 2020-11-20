#include "QueueManager.h"

void QueueManager::set_sync_queue_type(engine_types type) {
    sync_service_queue_type = type;
}

void QueueManager::set_client_queue_type(engine_types type) {
    client_queues_type = type;
}

void QueueManager::push_to_syncserv_queue(Message msg) {
    if (sync_service_queue == nullptr) {
        sync_service_queue = createNewQueue(sync_service_queue_type);
    }
    sync_service_queue->push_to_queue(msg);
}

void QueueManager::push_to_client_queue(Message msg, size_t id) {
    if (clients_queues.find(id) == clients_queues.end()) {
        clients_queues[id] = createNewQueue(client_queues_type);
    }
    clients_queues[id]->push_to_queue(msg);
}

Message QueueManager::pop_from_syncserv_queue() {
    return sync_service_queue->pop_from_queue();
}

Message QueueManager::pop_from_client_queue(size_t id) {
    return clients_queues[id]->pop_from_queue();
}

bool QueueManager::is_syncserv_queue_empty() {
    return sync_service_queue->is_empty();
}

bool QueueManager::is_user_queue_empty(size_t id) {
    return clients_queues[id]->is_empty();
}

Queue *QueueManager::createNewQueue(engine_types type) {
    switch (type) {
        case STD_QUEUE:
            return new StdQueue();
        case ON_DISK_QUEUE:
            return new OnDiskSaverQueue(DEFAULT_DIR_STRING);
    }
}
