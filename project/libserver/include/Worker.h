#ifndef SERV_WORKER_H
#define SERV_WORKER_H

#include <queue>
#include <memory>
#include <mutex>
#include <shared_mutex>
#include "Event.h"

class Worker {
protected:
    virtual void take_task() = 0;
    virtual void do_work() = 0;
    std::queue<Event>& m_clients_have_work;
    std::shared_ptr<std::mutex> m_have_work_mutex;

public:
    Worker(std::queue<Event>& event_queue, std::shared_ptr<std::mutex> mutex):
            m_clients_have_work(event_queue), m_have_work_mutex(mutex) { }
    virtual void run() = 0;
};

#endif //SERV_WORKER_H
