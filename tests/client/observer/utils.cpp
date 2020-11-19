//
// Created by yaroslav on 12.11.2020.
//

#include <Message.h>
#include "utils.h"
#include "random"
#include "iostream"

unsigned long my_random(unsigned int begin, unsigned int end) {
    std::random_device rd;
    std::mt19937 gener(rd());
    std::uniform_int_distribution<unsigned int> dist(begin, end);
    return dist(rd);
}

std::string random_str_gen(int length) {
    static std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    std::string result;
    result.resize(length);

    for (int i = 0; i < length; i++)
        result[i] = charset[my_random(0,charset.length())];

    return result;
}

bool operator==(const User &usr1, const User &usr2) {
    if (usr1.user_name == usr2.user_name)
        if (usr1.email == usr2.email)
            if (usr1.quota_limit == usr2.quota_limit)
                if (usr1.devise.device_name == usr2.devise.device_name)
                    if (usr1.devise.sync_folder == usr2.devise.sync_folder)
                        return 1;
    return 0;
}

bool operator==(const Message &mes1, const Message &mes2) {
    if (mes1.if_folder == mes2.if_folder)
        if (mes1.status == mes2.status)
            if (mes1.file_extension == mes2.file_extension)
                if (mes1.file_name == mes2.file_name)
                    if (mes1.file_path == mes2.file_path)
                        if (mes1.times_modified == mes2.times_modified)
                            if (mes1.version == mes2.version)
                                if (mes1.user == mes2.user)
                                    return 1;

    return 0;
}