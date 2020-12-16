#ifndef PROJECT_MESSAGE_H
#define PROJECT_MESSAGE_H
#include "iostream"
#include "Message.h"

Message create_message();
unsigned long my_random(unsigned int begin, unsigned int end);
std::string random_str_gen(int length);
bool operator==(const User &usr1, const User &usr2);
bool operator==(const Message &mes1, const Message &mes2);
#endif //PROJECT_MESSAGE_H
