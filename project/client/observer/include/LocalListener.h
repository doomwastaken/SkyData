#ifndef PROJECT_CLIENT_OBSERVER_LOCAL_LISTENER_H
#define PROJECT_CLIENT_OBSERVER_LOCAL_LISTENER_H
#include "iostream"
#include "messages.h"
#include "EventEditor.h"


class LocalListener : public EventEditor{
    void create_message();

public:
    int event() override;
};




#endif //PROJECT_CLIENT_LOCAL_LISTENER_H
