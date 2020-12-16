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
    local_list.event_listen(user.devise.sync_folder, user.user_name, user.email,
    user.devise.sync_folder, user.quota_limit, user.devise.device_name);
    return 0;
}

void Observer::update_client(const std::string &host, const std::string &port,
                             const std::string& host_storage, const std::string& port_storage) {
    boost::asio::io_context io_context;
    tcp::resolver resolver(io_context);
    tcp::resolver resolver_storage(io_context);
    tcp::resolver::results_type endpoints = resolver.resolve(host, port);
    tcp::resolver::results_type endpoints_storage = resolver_storage.resolve(host_storage, port_storage);
    MessageListener listener(io_context, endpoints, endpoints_storage);
    boost::thread t(boost::bind(&boost::asio::io_context::run, &io_context));


    devise_t device_1{user.devise.device_name, ""};
    user_t user_1{user.user_name, "", device_1, 10};

    // Hello message
    Message msg{1, status_t::LOGIN,
                1, "", "",
                1, "", user};

    listener.cl_con.write(msg);

    MessageUpdater updater;
    std::thread t1(&Observer::watch_local, this);
    while (true) {
        // if (local_list.event()) {

        // }
        //std::thread t2(&MessageUpdater::to_client_send, &updater);
        //t2.join();
        message_updater.to_client_send(listener.cl_con, listener.storage_connection);
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
    user.devise.device_name = "NE YARIK";
}
