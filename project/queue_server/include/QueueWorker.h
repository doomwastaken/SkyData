#ifndef PROJECT_QUEUEWORKER_H
#define PROJECT_QUEUEWORKER_H

#include "Worker.h"


class QueueWorker : public Worker {
protected:
    void take_task() override;
    void do_work() override;
    std::queue<Event>& m_clients_have_work;
    std::shared_ptr<std::mutex> m_have_work_mutex;

public:
    void run() override;
};


#endif //PROJECT_QUEUEWORKER_H
