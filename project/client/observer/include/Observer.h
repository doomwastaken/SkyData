#ifndef PROJECT_OBSERVER_H
#define PROJECT_OBSERVER_H
#include <iostream>

#include "EventListen.h"
#include "MessageListener.h"
#include "MessageUpdater.h"
#include "LocalListener.h"
#include "ClientToStorageConnection.h"



class Observer {
    MessageUpdater message_updater;
    User user;

    int watch_local();

public:
    void update_client(const std::string& host, const std::string& port,
                       const std::string& host_storage, const std::string& port_storage);
    Observer(std::string user_name, std::string device, std::string sync_folder);

};



#endif //PROJECT_OBSERVER_H
