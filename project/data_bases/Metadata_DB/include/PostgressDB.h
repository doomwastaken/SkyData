#ifndef PROJECT_POSTGRESSDB_H
#define PROJECT_POSTGRESSDB_H

#include <vector>

#include "Message.h"
#include "DataBase.h"

class PostgressDB: public DataBase {
public:
    PostgressDB();

    ~PostgressDB();

    virtual bool update(Message &send_message, std::vector<Message> &receive_messages) override;

private:
    virtual bool db_connect() override;

    virtual void db_disconnect() override;
};


#endif //PROJECT_POSTGRESSDB_H
