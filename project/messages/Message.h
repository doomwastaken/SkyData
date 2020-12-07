#ifndef PROJECT_MESSAGE_H
#define PROJECT_MESSAGE_H
#include <iostream>
#include <boost/serialization/access.hpp>

struct devise_t {
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
} typedef Devise;

struct user_t {
    std::string user_name;
    std::string email;
    devise_t devise;
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
} typedef User;

enum status_t {
    DELETE,
    MODIFIED,
    LOAD
};

struct Message {
    size_t version;
    status_t status;
    bool is_folder;
    size_t times_modified;
    std::string file_name;  // "file"
    std::string file_extension;  // ".png"
    size_t file_size;
    std::string file_path;  // "./dir/dir1/"
    user_t user;

private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int vers)
    {
        ar & version;
        ar & status;
        ar & is_folder;
        ar & times_modified;
        ar & file_name;
        ar & file_extension;
        ar & file_size;
        ar & file_path;
        ar & user;
    }
} typedef Message;



#endif //PROJECT_MESSAGE_H
