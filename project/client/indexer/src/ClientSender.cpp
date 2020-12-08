#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>

#include "ClientSender.h"
#include "ClientsConnection.h"

using boost::asio::ip::tcp;

int ClientSender::send(std::queue<std::shared_ptr<Message>> &messages) {
    boost::asio::ip::tcp::endpoint ep( boost::asio::ip::address::from_string("127.0.0.1"), 8001);


    boost::asio::io_context io_context;
    tcp::resolver resolver(io_context);
    tcp::resolver::results_type endpoints = resolver.resolve("127.0.0.1", "7777");

    ClientsConnection c(io_context, endpoints);

    boost::thread t(boost::bind(&boost::asio::io_context::run, &io_context));

    while (!messages.empty()) {
        std::shared_ptr<Message> mes = messages.front();
        if (m_internal_db.send_meta_data(mes)) {
            // TODO: Добавить логирование
            return 1;
        }
        if (m_cloud_storage.send_to_cloud(mes)) {
            // TODO: Добавить логирование
            return 1;
        }
        messages.pop();
        c.write(*mes);
        // TODO: Добавить логирование
    }

    return 0;
}
