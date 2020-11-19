#ifndef PROJECT_CLOUDSTORAGEDB_H
#define PROJECT_CLOUDSTORAGEDB_H

#include "CloudStorage.h"
#include "Message.h"

class CloudStorageDB: public CloudStorage {
public:
    CloudStorageDB();
    ~CloudStorageDB();

    void update() override;

protected:
    void db_connect() override;
    void db_disconnect() override;

private:
    void delete_file(Message &message) override;
    void add_file(Message &message) override;
};

#endif //PROJECT_CLOUDSTORAGEDB_H
