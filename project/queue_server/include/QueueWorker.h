#ifndef PROJECT_QUEUEWORKER_H
#define PROJECT_QUEUEWORKER_H

#include "Worker.h"


class QueueWorker : public Worker {
protected:
    void take_task() override;
    void do_work() override;

public:
    void run() override;
};


#endif //PROJECT_QUEUEWORKER_H
