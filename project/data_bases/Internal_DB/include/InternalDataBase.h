
#ifndef PROJECT_INTERNALDATABASE_H
#define PROJECT_INTERNALDATABASE_H

#include "Message.h"

class InternalDataBase {
public:
    InternalDataBase() = default;
    virtual ~InternalDataBase() = default;

    virtual bool update(Message &message) = 0;

    virtual int open() = 0;
    virtual void close() = 0;
};

#endif //PROJECT_INTERNALDATABASE_H