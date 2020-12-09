#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include "ClientsConnection.h"
#include "Message.h"

int main() {
    devise_t device1{"HomePC", "/home/denis/Desktop/Folder"};
    user_t user1{"Denis", "email@ml.com", device1, 10};

    Message msg1{10, status_t::MODIFIED, false,
                2, "main", "c",
                100, "/home/denis/Desktop/Folder", user1};


    devise_t device2{"HomePC", "/home/denis/Desktop/Folder"};
    user_t user2{"Denisqwe", "email@ml.com", device2, 10};

    Message msg2{10, status_t::MODIFIED, false,
                 2, "main", "c",
                 100, "/home/denis/Desktop/Folder", user2};

    boost::asio::ip::tcp::endpoint ep( boost::asio::ip::address::from_string("127.0.0.1"), 8001);


    boost::asio::io_context io_context;
    tcp::resolver resolver(io_context);
    tcp::resolver::results_type endpoints = resolver.resolve("127.0.0.1", "7777");

    ClientsConnection c(io_context, endpoints);

    boost::thread t(boost::bind(&boost::asio::io_context::run, &io_context));

    char line[1024];
    while (std::cin.getline(line, 1024))
    {
        if (strcmp(line, "q") == 0) { break; }
        if (strcmp(line, "1") == 0) { c.write(msg1); }
        if (strcmp(line, "2") == 0) { c.write(msg2); }
    }

    using namespace std::chrono_literals;
//    std::this_thread::sleep_for(1000ms);
//    c.write(msg);
//    std::this_thread::sleep_for(1000ms);
//    c.write(msg);
//    std::this_thread::sleep_for(1000ms);
    c.close();
    t.join();

    return EXIT_SUCCESS;
}