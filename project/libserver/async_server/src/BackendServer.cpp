#include "BackendServer.h"

BackendServer::BackendServer(boost::asio::io_context& io_context,
                             const boost::asio::ip::tcp::endpoint& endpoint):
                                AbstractServer(io_context, endpoint) {
    // TODO: Start accept in main code!
    // start_accept();
}

void BackendServer::start_accept() {
    boost::shared_ptr<ServerConnection> new_connect(new ServerConnection(m_io_context,
                                                                         std::shared_ptr<AbstractServer>(this)));
    m_acceptor.async_accept(new_connect->socket(),
                            boost::bind(
                                        &BackendServer::handle_accept,
                                        this,
                                        new_connect,
                                        boost::asio::placeholders::error));
}

void BackendServer::deliver_for_all(char* msg) {
    std::for_each(m_connections.begin(), m_connections.end(),
                  boost::bind(&ServerConnection::deliver, _1, boost::ref(msg)));
}

//TODO: Create logic
void BackendServer::on_readed_message(char* msg) {
    deliver_for_all(msg);
}