#ifndef PROJECT_DOWNLOADER_H
#define PROJECT_DOWNLOADER_H
#include <iostream>
#include <vector>
#include <Message.h>
#include <CloudStorageDB.h>
#include "CloudStorage.h"

template<class T>
class Downloader {
    std::vector<Message> messages;
    CloudStorageDB cloud_storage;

public:
     int downloader_files_from_cloud(Message message);
     Message push();
     Message pop();
};



#endif //PROJECT_DOWNLOADER_H

