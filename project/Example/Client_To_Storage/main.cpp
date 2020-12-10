#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include "ClientToStorageConnection.h"
#include "MessageStorage.h"

int main() {
    storage_devise_t device1{"HomePC", "/home/denis/Desktop/read_test"};
    storage_user_t user1{"Denis", "email@ml.com", device1, 10};

    MessageStorage msg1{10, storage_status_t::DOWNLOAD_FILE, false,
                 2, "lores", ".txt",
                 100, "/home/denis/Desktop/Folder", user1};


    storage_devise_t device2{"HomePC", "/home/denis/Desktop/read_test"};
    storage_user_t user2{"Denis", "email@ml.com", device2, 10};

    MessageStorage msg2{10, storage_status_t::PUSH_FILE, false,
                 2, "main", ".c",
                 100, "/home/denis/Desktop/Folder", user2};

//    boost::asio::ip::tcp::endpoint ep( boost::asio::ip::address::from_string("127.0.0.1"), 8001);


    boost::asio::io_context io_context;
    tcp::resolver resolver(io_context);
    tcp::resolver::results_type endpoints = resolver.resolve("127.0.0.1", "7779");

    ClientToStorageConnection c(io_context, endpoints);

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