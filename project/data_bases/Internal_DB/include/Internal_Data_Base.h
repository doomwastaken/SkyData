#ifndef PROJECT_INTERNAL_DATA_BASE_H
#define PROJECT_INTERNAL_DATA_BASE_H

#include "Message.h"

class Internal_Data_Base {
public:
    Internal_Data_Base() = default;
    ~Internal_Data_Base() = default;

    virtual void update(Message message) = 0;

protected:
    virtual void open() = 0;
    virtual void close() = 0;
};

#endif //PROJECT_INTERNAL_DATA_BASE_H
