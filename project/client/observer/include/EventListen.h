#ifndef PROJECT_EVENTLISTEN_H
#define PROJECT_EVENTLISTEN_H
#include <iostream>
#include <Message.h>

class EventListen {
protected:
    Message message;


public:
    virtual int event_listen(const std::string& path_str) = 0;
    Message get_message();
};

#endif //PROJECT_EVENTLISTEN_H
