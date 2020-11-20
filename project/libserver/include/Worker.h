#ifndef SERV_WORKER_H
#define SERV_WORKER_H

#include <queue>
#include <memory>
#include <mutex>
#include "Event.h"

class Worker {
protected:
    virtual void take_task() = 0;

    virtual void do_work() = 0;

public:
    virtual void run() = 0;

private:
    std::queue<Event> m_clients_have_work;

    std::shared_ptr<std::mutex> m_have_work_mutex;

};


#endif //SERV_WORKER_H
