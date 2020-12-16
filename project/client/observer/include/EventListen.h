#ifndef PROJECT_EVENTLISTEN_H
#define PROJECT_EVENTLISTEN_H
#include <iostream>
#include <Message.h>

class EventListen {
protected:
    Message message;


public:
    virtual int event_listen(const std::string& path_str, const std::string& user_name,
                             const std::string&, const std::string&, int, const std::string&) = 0;
    Message get_message();
};

#endif //PROJECT_EVENTLISTEN_H
