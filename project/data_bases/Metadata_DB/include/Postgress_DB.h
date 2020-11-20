#ifndef PROJECT_POSTGRESS_DB_H
#define PROJECT_POSTGRESS_DB_H

#include <vector>

#include "Message.h"
#include "Data_Base.h"

class Postgress_DB: public Data_Base {
public:
    Postgress_DB();

    ~Postgress_DB();

    virtual bool update(Message &send_message, std::vector<Message> &receive_messages) override;

private:
    virtual bool db_connect() override;

    virtual void db_disconnect() override;
};


#endif //PROJECT_POSTGRESS_DB_H
