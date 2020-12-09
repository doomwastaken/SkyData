#include "BackendServer.h"

void run_context(boost::asio::io_context& io_context) {
    io_context.run();
}

int main() {
    boost::asio::io_context io_context;

    tcp::resolver resolver(io_context);
//    tcp::resolver::results_type endpoint = resolver.resolve("127.0.0.1", "7777");
    boost::asio::ip::tcp::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), 7778);
//    AbstractServer m_server;
//    middle_end_connection connection(io_context, std::shared_ptr<AbstractServer>(&m_server));
//    abstract_connection connection(io_context, endpoint);
//    ClientsConnection clientsConnection(io_context, endpoint);
    BackendServer server(io_context, endpoint);
    server.start_accept();

    boost::thread_group tg;
    for (int i = 0; i < 5; i++) {
        auto* th (new boost::thread(&run_context, boost::ref(io_context)));
        tg.add_thread(th);
    }

    tg.join_all();

    return EXIT_SUCCESS;
}