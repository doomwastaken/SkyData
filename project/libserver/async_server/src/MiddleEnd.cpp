#include "MiddleEnd.h"

#include <utility>

MiddleEnd::MiddleEnd(boost::asio::io_context& io_context,
                     const boost::asio::ip::tcp::endpoint& endpoint)
: AbstractServer(io_context, endpoint) {
    // NOTE: Start accept in main code!
    // start_accept();
}

void MiddleEnd::set_client_for_backend(std::shared_ptr<ToBackendConnection> client) {
    m_backend = std::move(client);
}

void MiddleEnd::start_accept() {
    boost::shared_ptr<ServerConnection> new_connect(new ServerConnection(m_io_context,
                                                                         std::shared_ptr<AbstractServer>(this)));
    m_acceptor.async_accept(new_connect->socket(),
                            boost::bind(
                                        &MiddleEnd::handle_accept,
                                        this,
                                        new_connect,
                                        boost::asio::placeholders::error));
}

void MiddleEnd::deliver_for_all(char* msg) {
    std::for_each(m_connections.begin(), m_connections.end(),
                  boost::bind(&ServerConnection::deliver, _1, boost::ref(msg)));
}

void MiddleEnd::write_to_backend(char* msg) {
    m_backend->write(msg);
}

// TODO: create logic
void MiddleEnd::on_readed_message(char* msg) {
    write_to_backend(msg);
}

