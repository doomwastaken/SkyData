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

#include <QtWidgets>
#include "MainWidget.h"



//std::queue<std::shared_ptr<Message>> MessageUpdater::processed_messages = std::queue<std::shared_ptr<Message>> ();
std::queue<std::pair<std::shared_ptr<Message>, bool>> MessageUpdater::processed_messages = std::queue<std::pair<std::shared_ptr<Message>, bool>> ();
std::mutex MessageUpdater::mtx_stat;
//std::queue<std::pair<std::shared_ptr<Message>, bool>> processed_messages;

//Observer::Observer(std::string user_name, std::string email, std::string sync_folder)

int main(int argc, char** argv) {
    std::string name;
    std::string device;
    std::string sync_folder;
    QApplication a(argc, argv);
    MainWidget w(name, device, sync_folder);
    w.show();

    while(a.exec()) { ; }
    std::cout << name << " " << device << " " << sync_folder << std::endl;

//    Observer observer("Mr_white", "yorn", "/home/yaroslav/Techno_park/1_sem/notify/Test");
    Observer observer(name, device, sync_folder);
    observer.update_client("127.0.0.1", "7777", "127.0.0.1", "7779");
    //std::this_thread::sleep_for(100);
//}
}