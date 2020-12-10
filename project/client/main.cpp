//
// Created by Олег Реуцкий on 20.11.2020.
//

#include <iostream>
#include "ClientsConnection.h"
#include "MessageUpdater.h"
using namespace std;



std::queue<std::shared_ptr<Message>> MessageUpdater::processed_messages = std::queue<std::shared_ptr<Message>> ();
std::mutex MessageUpdater::mtx_stat;

int main() {



    return 0;
}