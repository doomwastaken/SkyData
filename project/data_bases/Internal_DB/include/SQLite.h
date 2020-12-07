#ifndef PROJECT_SQLITE_H
#define PROJECT_SQLITE_H

#include <sqlite3.h>
#include <memory>
#include "InternalDataBase.h"
#include "Message.h"

class SQLite: public InternalDataBase {
public:
    SQLite() = default;
    ~SQLite() override;

    bool update(Message &message) override;

    int open() override;
    void close() override;
    static int callback(void *NotUsed, int argc, char **argv, char **azColName);
private:
    sqlite3 *m_data_base{};

    int create_table_messages();
    bool insert(Message &message);
    bool del(Message &message);

};

#endif //PROJECT_SQLITE_H
