#ifndef PROJECT_DATABASE_H
#define PROJECT_DATABASE_H

#include "Message.h"

class DataBase {
public:
    DataBase() = default;

    virtual ~DataBase() = default;

    virtual std::vector<Message> update(Message &message) = 0;

    virtual bool open(std::string& config) = 0;

    virtual void close() = 0;

};

#endif //PROJECT_DATABASE_H