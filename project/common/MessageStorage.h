//
// Created by denis on 10.12.2020.
//

#ifndef ASYNC_CLIENT_QUEUE_SERVER_MESSAGESTORAGE_H
#define ASYNC_CLIENT_QUEUE_SERVER_MESSAGESTORAGE_H

#include <iostream>
#include <boost/serialization/access.hpp>

struct storage_devise_t {
    std::string device_name;
    std::string sync_folder;

private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int vers)
    {
        ar & device_name;
        ar & sync_folder;
    }
} typedef StorageDevise;

struct storage_user_t {
    std::string user_name;
    std::string email;
    storage_devise_t devise;
    int quota_limit;

private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int vers)
    {
        ar & user_name;
        ar & email;
        ar & devise;
        ar & quota_limit;
    }
} typedef StorageUser;

enum storage_status_t {
    PUSH_FILE,
    DOWNLOAD_FILE,
};

struct MessageStorage {
    size_t version;
    storage_status_t status;
    bool if_folder;
    size_t times_modified;
    std::string file_name;  // "file"
    std::string file_extension;  // ".png"
    size_t file_size;
    std::string file_path;  // "./dir/dir1/"
    storage_user_t user;
    std::string RAW_BYTES;  // RAW_BYTES of data

private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int vers)
    {
        ar & version;
        ar & status;
        ar & if_folder;
        ar & times_modified;
        ar & file_name;
        ar & file_extension;
        ar & file_size;
        ar & file_path;
        ar & user;
        ar & RAW_BYTES;
    }
} typedef MessageStorage;

#endif //ASYNC_CLIENT_QUEUE_SERVER_MESSAGESTORAGE_H
