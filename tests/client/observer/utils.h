#ifndef PROJECT_UTILS_H
#define PROJECT_UTILS_H
#include "iostream"
#include "Message.h"

unsigned long my_random(unsigned int begin, unsigned int end);
std::string random_str_gen(int length);
bool operator==(const User &usr1, const User &usr2);
bool operator==(const Message &mes1, const Message &mes2);
#endif //PROJECT_UTILS_H
