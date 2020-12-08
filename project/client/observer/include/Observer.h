#ifndef PROJECT_OBSERVER_H
#define PROJECT_OBSERVER_H
#include <iostream>
#include "Downloader.h"
#include "EventListen.h"
#include "MessageUpdater.h"
#include <queue>

template<class T>
class Observer {
    EventListen* event;
    Downloader<T> downloader;
    MessageUpdater message_updater;
    std::queue<Message> packet;

    int watch_message_from_server();
    int watch_local();

public:
    void update_client();

};



#endif //PROJECT_OBSERVER_H
