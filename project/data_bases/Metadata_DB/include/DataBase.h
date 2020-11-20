#ifndef PROJECT_DATABASE_H
#define PROJECT_DATABASE_H

#include <vector>

#include "Message.h"

class DataBase {
public:
    DataBase() = default;

    ~DataBase() = default;

    virtual bool update(Message &send_message, std::vector<Message> &receive_messages) = 0;

protected:
    virtual bool db_connect() = 0;
    virtual void db_disconnect() = 0;
};


#endif //PROJECT_DATABASE_H
