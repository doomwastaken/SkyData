#ifndef PROJECT_DATA_BASE_H
#define PROJECT_DATA_BASE_H

#include <vector>

#include "Message.h"

class Data_Base {
public:
    Data_Base() = default;

    ~Data_Base() = default;

    virtual bool update(Message &send_message, std::vector<Message> &receive_messages) = 0;

protected:
    virtual bool db_connect() = 0;
    virtual void db_disconnect() = 0;
};


#endif //PROJECT_DATA_BASE_H
