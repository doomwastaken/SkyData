//#include "Sync_Service.h"
#include "PostgressDB.h"
#include "BackendServer.h"
#include "ServerConnection.h"
#include "Message.h"
#include <iostream>
#include <fstream>

void run_context(boost::asio::io_context& io_context) {
    io_context.run();
}

int main() {
    std::string conf = "dbname = postgres user = postgres password = Bars hostaddr = 127.0.0.1 port = 5432";
    auto db = std::make_shared<PostgressDB>();
    db->open(conf);
    db->create_users_devises_table();
    db->create_users_files_table();

    boost::asio::io_context io_context;

    tcp::resolver resolver(io_context);
    boost::asio::ip::tcp::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), 7778);
    BackendServer server(io_context, endpoint, db);
    server.start_accept();

    boost::thread_group tg;
    for (int i = 0; i < 5; i++) {
        auto* th (new boost::thread(&run_context, boost::ref(io_context)));
        tg.add_thread(th);
    }

    tg.join_all();


//    Message message;
//    message.user.devise.device_name = "iPhone";
//    message.user.devise.sync_folder = "/dev/null/";
//    message.user.user_name = "Oleg";
//    message.user.email = "astlok@ya.ru";
//    message.user.quota_limit = 228;
//    message.version = 3;
//    message.status = DELETE;
//    message.times_modified = 322;
//    message.file_name = "kek";
//    message.file_extension = ".cpp";
//    message.file_size = 1488;
//    message.file_path = "/usr/local/bin/";
//
//    db.insert(message);

  return 0;
}
