#ifndef ASYNC_CLIENT_QUEUE_SERVER_CLIENTS_CONNECTION_H
#define ASYNC_CLIENT_QUEUE_SERVER_CLIENTS_CONNECTION_H

#include "AbstractConnection.h"

class ClientsConnection : public AbstractConnection {
public:
    ClientsConnection(boost::asio::io_context& io_context, const tcp::resolver::results_type& endpoint);

    void write(const std::string& msg);

    void close();

private:

    void handle_connect(const boost::system::error_code& error);

    void handle_read(const boost::system::error_code& error) override;

    void do_write(std::string msg);

    void handle_write(const boost::system::error_code& error) override;

private:
    boost::asio::io_context& m_io_context;
    tcp::resolver::results_type endpoint;
};


#endif //ASYNC_CLIENT_QUEUE_SERVER_CLIENTS_CONNECTION_H
