#include "MessageListener.h"

Message MessageListener::to_listen_message() {
    return message;
}

int MessageListener::event() {
    return 0;
}

