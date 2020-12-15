#include "Observer.h"



//void Observer::watch_message_from_server(const std::string& host, const size_t& port) {
//    boost::asio::io_service io;
//    boost::asio::io_context io_context;
//    tcp::resolver resolver(io_context);
//    tcp::resolver::results_type endpoints = resolver.resolve("127.0.0.1", "7777");
//
//    MessageListener mes_list(io_context, endpoints);
//    boost::thread t(boost::bind(&boost::asio::io_context::run, &io_context));
//   // boost::asio::deadline_timer timer(io, boost::posix_time::seconds(5));
//
//    while (true) {
//
//    }
//
// //   return;
//}


int Observer::watch_local() {
    LocalListener local_list;
    local_list.event_listen(user.devise.sync_folder);
    std::cout << "FUUUUUUUUUUUUUUUUUUUUUUUCK\n";
//    while (true) {
//
//        sleep(10);
//    }
    return 0;
}


void Observer::update_client(const std::string &host, const std::string &port) {
    boost::asio::io_context io_context;
    tcp::resolver resolver(io_context);
    tcp::resolver::results_type endpoints = resolver.resolve(host, port);
    MessageListener listener(io_context, endpoints);
    boost::thread t(boost::bind(&boost::asio::io_context::run, &io_context));


    MessageUpdater updater;
    std::thread t1(&Observer::watch_local, this);
    while (true) {
        // if (local_list.event()) {

        // }
        //std::thread t2(&MessageUpdater::to_client_send, &updater);
        //t2.join();
        message_updater.to_client_send(listener.cl_con);
        sleep(4);
        // ToDo поставить таймер
       // break; // не забыть убрать

    }


}

Observer::Observer(std::string user_name, std::string email, std::string sync_folder) {
    user.user_name = user_name;
    user.email = email;
    user.devise.sync_folder = sync_folder;
    user.quota_limit = 10;
    user.devise.device_name = "BAOBAB";
}
