#ifndef PROJECT_CLOUDSTORAGE_H
#define PROJECT_CLOUDSTORAGE_H

#include <messages.h>

class CloudStorage {
public:
    CloudStorage() = default;
    ~CloudStorage() = default;

    virtual void update() = 0;

protected:
    virtual void db_connect() = 0;
    virtual void db_disconnect() = 0;

private:
    virtual void delete_file(Message &message) = 0;
    virtual void add_file(Message &message) = 0;
};

#endif //PROJECT_CLOUDSTORAGE_H
