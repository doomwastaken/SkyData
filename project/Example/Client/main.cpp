#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include "ClientsConnection.h"
#include "Message.h"

int main() {

    devise_t device1{"HomePC", "/home/denis/Desktop/Folder"};
    user_t user1{"Denis", "email@ml.com", device1, 10};

    Message message;
    message.user.devise.device_name = "iPhone";
    message.user.devise.sync_folder = "/dev/null/";
    message.user.user_name = "Oleg";
    message.user.email = "astlok@ya.ru";
    message.user.quota_limit = 228;
    message.version = 3;
    message.status = NEW_USER;
    message.times_modified = 322;
    message.file_name = "kek";
    message.file_extension = ".cpp";
    message.file_size = 1488;
    message.file_path = "/usr/local/bin/";

    Message message2;
    message2.user.devise.device_name = "mac";
    message2.user.devise.sync_folder = "/dev/null/";
    message2.user.user_name = "Oleg";
    message2.user.email = "astlok@ya.ru";
    message2.user.quota_limit = 228;
    message2.version = 3;
    message2.status = NEW_DEVISE;
    message2.times_modified = 322;
    message2.file_name = "kek";
    message2.file_extension = ".cpp";
    message2.file_size = 1488;
    message2.file_path = "/usr/local/bin/";

    Message message3;
    message3.user.devise.device_name = "mac";
    message3.user.devise.sync_folder = "/dev/null/";
    message3.user.user_name = "Oleg";
    message3.user.email = "astlok@ya.ru";
    message3.user.quota_limit = 228;
    message3.version = 3;
    message3.status = CREATE;
    message3.times_modified = 322;
    message3.file_name = "lul";
    message3.file_extension = ".html";
    message3.file_size = 1488;
    message3.file_path = "/usr/local/bin/";

    Message message4;
    message4.user.devise.device_name = "mac";
    message4.user.devise.sync_folder = "/dev/null/";
    message4.user.user_name = "Oleg";
    message4.user.email = "astlok@ya.ru";
    message4.user.quota_limit = 228;
    message4.version = 3;
    message4.status = DELETE;
    message4.times_modified = 322;
    message4.file_name = "kek";
    message4.file_extension = ".cpp";
    message4.file_size = 1488;
    message4.file_path = "/usr/local/bin/";
//    Message msg1{10, status_t::MODIFIED, false,
//                2, "main", "c",
//                100, "/home/denis/Desktop/Folder", user1};


//    devise_t device2{"HomePC", "/home/denis/Desktop/Folder"};
//    user_t user2{"Denisqwe", "email@ml.com", device2, 10};

//    Message msg2{10, status_t::MODIFIED, false,
//                 2, "main", "c",
//                 100, "/home/denis/Desktop/Folder", user2};


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
        if (strcmp(line, "1") == 0) { c.write(message); }
        if (strcmp(line, "2") == 0) { c.write(message2); }
        if (strcmp(line, "3") == 0) {
            c.write(message3); }
        if (strcmp(line, "4") == 0) {
            std::cout << "4 write" << std::endl;
            c.write(message4); }
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