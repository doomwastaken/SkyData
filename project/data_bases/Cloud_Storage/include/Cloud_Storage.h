#ifndef PROJECT_CLOUD_STORAGE_H
#define PROJECT_CLOUD_STORAGE_H

#include "Message.h"

class Cloud_Storage {
public:
    Cloud_Storage() = default;
    ~Cloud_Storage() = default;

    virtual void update() = 0;

protected:
    virtual void db_connect() = 0;
    virtual void db_disconnect() = 0;

    virtual void delete_file(Message message) = 0;
    virtual void add_file(Message message) = 0;
};

#endif //PROJECT_CLOUD_STORAGE_H
