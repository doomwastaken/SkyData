#ifndef PROJECT_DATA_BASE_WORKER_H
#define PROJECT_DATA_BASE_WORKER_H

#include "Worker.h"
#include "DataBase.h"


class DataBaseWorker : public Worker {
public:
    DataBaseWorker(DataBase &data_base,
                   std::queue<Event> &m_clients_have_work,
                   std::shared_ptr<std::mutex> &m_have_work_mutex) :
    m_clients_have_work(m_clients_have_work),
    m_have_work_mutex(m_have_work_mutex),
    data_base(data_base)
    {}

    virtual void take_task() override;

    virtual void do_work() override;

private:
    virtual void run() override;

    std::queue<Event> m_clients_have_work;

    std::shared_ptr<std::mutex> m_have_work_mutex;

    DataBase &data_base;
};


#endif //PROJECT_DATA_BASE_WORKER_H
