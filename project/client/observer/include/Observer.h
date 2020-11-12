#ifndef PROJECT_OBSERVER_H
#define PROJECT_OBSERVER_H
#include <iostream>
#include "Cloud_Storage_Downloader.h"

template<class T>
class Observer {
    Cloud_Storage_Downloader<T> cloud_storage_down;
    //Queue_API реализация после мержа
public:
    void update_client();
    int load_to_machine();

};

#endif //PROJECT_OBSERVER_H
