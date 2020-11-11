#ifndef PROJECT_POSTGRESS_INTERNAL_DB_H
#define PROJECT_POSTGRESS_INTERNAL_DB_H

#include "Internal_Data_Base.h"
#include "Message.h"

class Postgress_Internal_DB: public Internal_Data_Base {
public:
    Postgress_Internal_DB();
    ~Postgress_Internal_DB();

    void update(Message message) override;

private:
    void open() override;
    void close() override;
};

#endif //PROJECT_POSTGRESS_INTERNAL_DB_H
