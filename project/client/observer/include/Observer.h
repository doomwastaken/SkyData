#ifndef PROJECT_OBSERVER_H
#define PROJECT_OBSERVER_H
#include <iostream>
#include "Cloud_Storage_Downloader.h"

class Observer {
    Cloud_Storage_Downloader cloud_storage_down;
public:
    void update_client();
    void load_to_machine();

};

#endif //PROJECT_OBSERVER_H
