#include "CloudStorageAPI.h"

int CloudStorageAPI::connect() {
    pqxx::connection C;
    return 0;
}

int CloudStorageAPI::push(const std::shared_ptr<Message>& mes) {
    return 0;
}

int CloudStorageAPI::pop() {
    return 0;
}

int CloudStorageAPI::erase(const std::shared_ptr<Message> &mes) {
    return 0;
}


