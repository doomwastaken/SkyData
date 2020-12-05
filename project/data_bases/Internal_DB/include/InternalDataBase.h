#ifndef PROJECT_INTERNALDATABASE_H
#define PROJECT_INTERNALDATABASE_H

#include "Message.h"

class InternalDataBase {
public:
    InternalDataBase() = default;
   virtual ~InternalDataBase() = default;

    virtual void update(Message &message) = 0;

//protected:
    virtual bool open(const std::string& config) = 0;  // строку общую составляем из вне (Пользователь, пароль, название базы данных, хост, порт)
    virtual void close() = 0;
    virtual bool create_users_table() = 0;
};

#endif //PROJECT_INTERNALDATABASE_H
