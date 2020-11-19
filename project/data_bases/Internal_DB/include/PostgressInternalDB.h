#ifndef PROJECT_POSTGRESSINTERNALDB_H
#define PROJECT_POSTGRESSINTERNALDB_H

#include "InternalDataBase.h"
#include "Message.h"

class PostgressInternalDB: public InternalDataBase {
public:
    PostgressInternalDB();
    ~PostgressInternalDB();

    void update(Message &message) override;

private:
    void open() override;
    void close() override;
};

#endif //PROJECT_POSTGRESSINTERNALDB_H
