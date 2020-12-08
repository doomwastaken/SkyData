#ifndef PROJECT_EVENTLISTEN_H
#define PROJECT_EVENTLISTEN_H
#include <iostream>
#include <Message.h>

class EventListen {
protected:
    Message message;
    enum event {
        local_detele,
        local_download,
        queue_mes_came
    };

public:
    virtual int event() = 0;
    Message get_message();
};

#endif //PROJECT_EVENTLISTEN_H
