//
// Created by denis on 03.12.2020.
//

#include "backend_server.h"

backend_server::backend_server(boost::asio::io_context& io_context,
                               const boost::asio::ip::tcp::endpoint& endpoint)
: abstract_server(io_context, endpoint) {
    // TODO: Start accept in main code!
    // start_accept();
    }

void backend_server::start_accept() {
    boost::shared_ptr<server_connection> new_connect(new server_connection(io_context_, std::shared_ptr<abstract_server>(this)));
    acceptor_.async_accept(new_connect->socket(),
                           boost::bind(&backend_server::handle_accept, this, new_connect,
                                       boost::asio::placeholders::error));
}

void backend_server::deliver_for_all(char* msg) {
    std::for_each(connections.begin(), connections.end(),
                  boost::bind(&server_connection::deliver, _1, boost::ref(msg)));
}

//TODO: Create logic
void backend_server::on_readed_message(char* msg) {
    deliver_for_all(msg);
}