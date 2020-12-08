#include "MessageListener.h"
#include "ClientsConnection.h"

Message MessageListener::to_listen_message() {
    return message;
}

int MessageListener::event() {
    boost::asio::ip::tcp::endpoint ep( boost::asio::ip::address::from_string("127.0.0.1"), 8001);


    boost::asio::io_context io_context;
    tcp::resolver resolver(io_context);
    tcp::resolver::results_type endpoints = resolver.resolve("127.0.0.1", "7777");

    ClientsConnection c(io_context, endpoints);

    boost::thread t(boost::bind(&boost::asio::io_context::run, &io_context));

    return 0;
}

