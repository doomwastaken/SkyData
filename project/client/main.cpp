//
// Created by Олег Реуцкий on 20.11.2020.
//

#include <iostream>
#include "ClientsConnection.h"
#include "MessageUpdater.h"
using namespace std;

void prov() {
    int a = 0;
    while (a < 100000) {
        ++a;
    }
    cout << a << endl;
}


void do_some_work()
{
    std::cout << "Hello world!" << std::endl;
    std::thread t1(prov);
    t1.join();
    return;
}

std::queue<std::shared_ptr<Message>> MessageUpdater::processed_messages = std::queue<std::shared_ptr<Message>> ();

int main() {
//    auto func22 = []() {
//        std::cout << "Hello world!"  << std::endl;
//    };
    cout << this_thread::get_id() << endl;
   // std::thread thread1(func22);
    do_some_work();

   // thread1.join();

//    std::thread thread2(do_some_work);
//    thread2.detach();


    return 0;
}