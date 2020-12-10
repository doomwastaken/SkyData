#include "StorageServer.h"
#include "ToBackendConnection.h"

void run_context(boost::asio::io_context& io_context) {
    io_context.run();
}

int main() {
    boost::asio::io_context io_context;
    boost::asio::ip::tcp::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), 7779);
    StorageServer server(io_context, endpoint);
    server.start_accept();

    boost::thread_group tg;
    for (int i = 0; i < 5; i++) {
        auto* th (new boost::thread(&run_context, boost::ref(io_context)));
        tg.add_thread(th);
    }

    char line[1024];
    while (std::cin.getline(line, 1024))
    {
        using namespace std; // For strlen and memcpy.
        std::string msg(line);
        msg += "\n";
    }

    tg.join_all();
    return EXIT_SUCCESS;
}