//
// Created by denis on 03.12.2020.
//

#include "middle_end.h"

middle_end::middle_end(boost::asio::io_context& io_context,
                       const boost::asio::ip::tcp::endpoint& endpoint)
: abstract_server(io_context, endpoint) {
    // TODO: Start accept in main code!
    // start_accept();
}

void middle_end::set_client_for_backend(std::shared_ptr<to_backend_connection> client) {
    backend = client;
}

void middle_end::start_accept() {
    boost::shared_ptr<server_connection> new_connect(new server_connection(io_context_, std::shared_ptr<abstract_server>(this)));
    acceptor_.async_accept(new_connect->socket(),
                           boost::bind(&middle_end::handle_accept, this, new_connect,
                                       boost::asio::placeholders::error));
}

void middle_end::deliver_for_all(char* msg) {
    std::for_each(connections.begin(), connections.end(),
                  boost::bind(&server_connection::deliver, _1, boost::ref(msg)));
}

void middle_end::write_to_backend(char* msg) {
    backend->write(msg);
}

// TODO: create logic
void middle_end::on_readed_message(char* msg) {
    write_to_backend(msg);
}

