#include "Postgress_DB.h"

Postgress_DB::Postgress_DB() {
    if (!db_connect()) {
        std::cerr << "Not connected";
    }
}

Postgress_DB::~Postgress_DB() {
    db_disconnect();
}

bool Postgress_DB::db_connect() {
    return false;
}

void Postgress_DB::db_disconnect() {

}

bool Postgress_DB::update(Message &send_message, std::vector<Message> &receive_messages) {
    return false;
}
