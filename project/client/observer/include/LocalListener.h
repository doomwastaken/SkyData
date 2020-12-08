#ifndef PROJECT_CLIENT_OBSERVER_LOCAL_LISTENER_H
#define PROJECT_CLIENT_OBSERVER_LOCAL_LISTENER_H
#include "iostream"
#include "Message.h"
#include "EventListen.h"


class LocalListener : public EventListen{
    void create_message();

public:
    int event() override;
};




#endif //PROJECT_CLIENT_LOCAL_LISTENER_H
