#ifndef PROJECT_DATABASE_H
#define PROJECT_DATABASE_H

#include "Message.h"

class DataBase {
public:
    DataBase() = default;
    virtual ~DataBase() = default;

    virtual std::vector<Message> update(Message &message) = 0;

//    virtual void insert(Message &message) = 0;
//
////protected:
//    virtual bool open(const std::string& config) = 0;  // строку общую составляем из вне (Пользователь, пароль, название базы данных, хост, порт)
//
//    virtual void close() = 0;
//
//    virtual bool create_users_table() = 0;
};

#endif //PROJECT_DATABASE_H