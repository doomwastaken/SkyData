#ifndef PROJECT_POSTGRESSINTERNALDB_H
#define PROJECT_POSTGRESSINTERNALDB_H

#include "InternalDataBase.h"
#include "Message.h"
#include "pqxx/pqxx"

class PostgressInternalDB: public InternalDataBase {
public:
    PostgressInternalDB();
    ~PostgressInternalDB() override;

    void update(Message &message) override;

private:
    std::shared_ptr<pqxx::connection> connect;

    bool open(const std::string& config) override;
    void close() override;
    bool create_users_table() override;
};

#endif //PROJECT_POSTGRESSINTERNALDB_H
