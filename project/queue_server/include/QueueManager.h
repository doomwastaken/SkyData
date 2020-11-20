#ifndef PROJECT_QUEUEMANAGER_H
#define PROJECT_QUEUEMANAGER_H

#include <map>
#include "Queue.h"
#include "StdQueue.h"
#include "OnDiskSaverQueue.h"

const std::string DEFAULT_DIR_STRING = "./";

enum engine_types {
    STD_QUEUE = 0,
    ON_DISK_QUEUE,
};

class QueueManager {
private:
    Queue* sync_service_queue;
    std::map<size_t, Queue*> clients_queues;
    QueueManager() : sync_service_queue(nullptr) {}
    engine_types sync_service_queue_type;
    engine_types client_queues_type;
    Queue* createNewQueue(engine_types type);

public:
    static QueueManager &queue_manager() {
        static QueueManager qm;
        return qm;
    }
    ~QueueManager() {
        delete sync_service_queue;
    }

    void set_sync_queue_type(engine_types type);
    void set_client_queue_type(engine_types type);
    void push_to_syncserv_queue(Message msh);
    void push_to_client_queue(Message msh, size_t id);
    Message pop_from_syncserv_queue();
    Message pop_from_client_queue(size_t id);
    bool is_syncserv_queue_empty();
    bool is_user_queue_empty(size_t id);

};


#endif //PROJECT_QUEUEMANAGER_H
