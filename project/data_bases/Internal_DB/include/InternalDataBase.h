#ifndef PROJECT_INTERNALDATABASE_H
#define PROJECT_INTERNALDATABASE_H

#include "Message.h"

class InternalDataBase {
public:
    InternalDataBase() = default;
    ~InternalDataBase() = default;

    virtual void update(Message &message) = 0;

protected:
    virtual void open() = 0;
    virtual void close() = 0;
};

#endif //PROJECT_INTERNALDATABASE_H
