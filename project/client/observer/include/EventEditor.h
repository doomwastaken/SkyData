//
// Created by yaroslav on 19.11.2020.
//

#ifndef PROJECT_EVENTEDITOR_H
#define PROJECT_EVENTEDITOR_H
#include <iostream>
#include <messages.h>

class EventEditor {
protected:
    Message message;

public:
    virtual int event() = 0;
    Message get_message();
};

#endif //PROJECT_EVENTEDITOR_H
