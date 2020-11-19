#ifndef PROJECT_OBSERVER_H
#define PROJECT_OBSERVER_H
#include <iostream>
#include "Downloader.h"
#include "EventEditor.h"
#include "MessageUpdater.h"

template<class T>
class Observer {
    EventEditor* event;
    Downloader<T> downloader;
    MessageUpdater message_updater;

    int watch_message_from_server();
    int watch_local();

public:
    void update_client();

};



#endif //PROJECT_OBSERVER_H
