//
// Created by denis on 03.12.2020.
//

#include "../../server/middle_end/middle_end.h"

void run_context(boost::asio::io_context& io_context) {
    io_context.run();
}

int main() {
    boost::asio::io_context io_context;
    boost::asio::ip::tcp::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), 7777);
    middle_end server(io_context, endpoint);
    server.start_accept();

    boost::thread_group tg;
    for (int i = 0; i < 5; i++) {
        auto* th (new boost::thread(&run_context, boost::ref(io_context)));
        tg.add_thread(th);
    }

    boost::asio::io_context io_backend_context;
    boost::asio::ip::tcp::resolver resolver(io_context);
    boost::asio::ip::tcp::resolver::results_type endpoints = resolver.resolve("127.0.0.1", "7778");

    ToBackendConnection c(io_backend_context, endpoints);

    c.set_owner_server(std::shared_ptr<middle_end>(&server));
    server.set_client_for_backend(std::shared_ptr<ToBackendConnection>(&c));

    boost::thread t(boost::bind(&boost::asio::io_context::run, &io_backend_context));

    char line[1024];
    while (std::cin.getline(line, 1024))
    {
        using namespace std; // For strlen and memcpy.
        std::string msg(line);
        msg += "\n";
        c.write(msg);
    }

    c.close();
    t.join();

    tg.join_all();
    return EXIT_SUCCESS;
}