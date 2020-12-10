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
    return 0;
}


void Observer::update_client(const std::string &host, const std::string &port) {
    boost::asio::io_context io_context;
    tcp::resolver resolver(io_context);
    tcp::resolver::results_type endpoints = resolver.resolve(host, port);
    MessageListener listener(io_context, endpoints);
    boost::thread t(boost::bind(&boost::asio::io_context::run, &io_context));

    LocalListener local_list;
    MessageUpdater updater;
    std::thread t1(&Observer::watch_local, this);
    while (true) {
        // if (local_list.event()) {

        // }
        std::thread t2(&MessageUpdater::to_client_send, &updater);
        t2.join();
        break; // не забыть убрать

    }


}
