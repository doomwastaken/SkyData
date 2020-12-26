#ifndef ASYNC_CLIENT_QUEUE_SERVER_SERVER_CONNECTION_H
#define ASYNC_CLIENT_QUEUE_SERVER_SERVER_CONNECTION_H


#include "Message.h"
#include "AbstractConnection.h"

class AbstractServer;

class ServerConnection : public AbstractConnection, public boost::enable_shared_from_this<ServerConnection> {
public:
    ServerConnection(boost::asio::io_context& io_context, std::shared_ptr<AbstractServer> srvr);
    virtual ~ServerConnection() = default;

    boost::asio::ip::tcp::socket& socket();
    void start();
    void handle_read(const boost::system::error_code& error) override;
    void deliver(std::string msg);
    void find_file_and_send(Message msg);
    void change_file_on_server(Message msg);
    void handle_write(const boost::system::error_code& error) override;

private:
    std::shared_ptr<AbstractServer> m_server_ptr;
};


#endif //ASYNC_CLIENT_QUEUE_SERVER_SERVER_CONNECTION_H
