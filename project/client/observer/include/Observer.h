#ifndef PROJECT_OBSERVER_H
#define PROJECT_OBSERVER_H
#include <iostream>
#include "Downloader.h"
#include "EventListen.h"
#include "MessageListener.h"
#include "MessageUpdater.h"
#include "LocalListener.h"



class Observer {
    //MessageListener mes_list;
    //Downloader<T> downloader;

    MessageUpdater message_updater;
    User user;


   // void watch_message_from_server(const std::string& host, const size_t& port);
    int watch_local();

public:
    void update_client(const std::string& host, const std::string& port);
    Observer(std::string user_name, std::string email, std::string sync_folder);

};



#endif //PROJECT_OBSERVER_H
