#ifndef PROJECT_CLOUDSTORAGEAPI_H
#define PROJECT_CLOUDSTORAGEAPI_H

#include <queue>
#include "Message.h"
#include "memory"
#include <pqxx/pqxx>


class CloudStorageAPI {
public:
    int connect();
    int push(const std::shared_ptr<Message>& mes);
    int pop();
    int erase(const std::shared_ptr<Message>& mes);

private:
    std::queue<std::shared_ptr<Message>> message;

};

#endif //PROJECT_CLOUDSTORAGEAPI_H
