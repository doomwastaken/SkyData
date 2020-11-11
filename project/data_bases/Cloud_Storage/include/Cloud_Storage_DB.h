#ifndef PROJECT_CLOUD_STORAGE_DB_H
#define PROJECT_CLOUD_STORAGE_DB_H

#include "Cloud_Storage.h"
#include "Message.h"

class Cloud_Storage_DB: public Cloud_Storage {
public:
    Cloud_Storage_DB();
    ~Cloud_Storage_DB();

    void update() override;

private:
    void db_connect() override;
    void db_disconnect() override;

    void delete_file(Message message) override;
    void add_file(Message message) override;
};

#endif //PROJECT_CLOUD_STORAGE_DB_H
