#include "PostgressDB.h"

PostgressDB::PostgressDB() {
    if (!db_connect()) {
        std::cerr << "Not connected";
    }
}

PostgressDB::~PostgressDB() {
    db_disconnect();
}

bool PostgressDB::db_connect() {
    return false;
}

void PostgressDB::db_disconnect() {

}

bool PostgressDB::update(Message &send_message, std::vector<Message> &receive_messages) {
    return false;
}
