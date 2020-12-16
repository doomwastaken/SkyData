//
// Created by Олег Реуцкий on 20.11.2020.
//

#include <iostream>
#include "ClientsConnection.h"
#include "MessageUpdater.h"
#include "../liblistener/include/Listener.h"
#include "Observer.h"
#include "ClientSender.h"
#include "MessageListener.h"
using namespace std;



//std::queue<std::shared_ptr<Message>> MessageUpdater::processed_messages = std::queue<std::shared_ptr<Message>> ();
std::queue<std::pair<std::shared_ptr<Message>, bool>> MessageUpdater::processed_messages = std::queue<std::pair<std::shared_ptr<Message>, bool>> ();
std::mutex MessageUpdater::mtx_stat;
//std::queue<std::pair<std::shared_ptr<Message>, bool>> processed_messages;

//Observer::Observer(std::string user_name, std::string email, std::string sync_folder)

int main() {
    Observer observer("Mr_white", "yorn", "/home/denis/Desktop/client_test");
    observer.update_client("127.0.0.1", "7777", "127.0.0.1", "7779");
    //std::this_thread::sleep_for(100);
//}
}