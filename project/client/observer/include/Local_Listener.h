#ifndef PROJECT_CLIENT_OBSERVER_LOCAL_LISTENER_H
#define PROJECT_CLIENT_OBSERVER_LOCAL_LISTENER_H
#include "iostream"
#include "messages.h"


class Local_Listener{
public:
     Local_Listener() = default;
    ~Local_Listener() = default;
    Message list_local_machine();


private:
    Message message;
    void create_message();
};




#endif //PROJECT_CLIENT_LOCAL_LISTENER_H
