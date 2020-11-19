#ifndef PROJECT_DOWNLOADER_H
#define PROJECT_DOWNLOADER_H
#include <iostream>
#include <vector>
#include <messages.h>

class Downloader {
    std::vector<Message> messages;
    // CloudStorage cloud_storage

public:
     int downloader_files_from_cloud(Message message);
     void push();
     void pop();
};

#endif //PROJECT_DOWNLOADER_H

