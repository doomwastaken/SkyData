#ifndef ASYNC_CLIENT_QUEUE_SERVER_SERVER_CONNECTION_H
#define ASYNC_CLIENT_QUEUE_SERVER_SERVER_CONNECTION_H


#include "AbstractConnection.h"

class AbstractServer;

class ServerConnection : public AbstractConnection, public boost::enable_shared_from_this<ServerConnection> {
public:
    ServerConnection(boost::asio::io_context& io_context, std::shared_ptr<AbstractServer> srvr);

    boost::asio::ip::tcp::socket& socket();

//    'write' 'close' 'handle_connect' 'do_write'
    void start();

    void handle_read(const boost::system::error_code& error) override;

    void deliver(std::string msg);

    void handle_write(const boost::system::error_code& error) override;

    virtual ~ServerConnection() = default;

private:
    std::shared_ptr<AbstractServer> m_server_ptr;
};


#endif //ASYNC_CLIENT_QUEUE_SERVER_SERVER_CONNECTION_H
