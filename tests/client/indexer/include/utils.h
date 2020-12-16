#ifndef PROJECT_MESSAGE_H
#define PROJECT_UTILS_H

#include "iostream"
#include "Message.h"

Message create_message();
bool operator==(const User &usr1, const User &usr2);
bool operator==(const Message &mes1, const Message &mes2);

#endif //PROJECT_MESSAGE_H
