//
// Created by denis on 03.12.2020.
//

#ifndef ASYNC_CLIENT_QUEUE_SERVER_CLIENTS_CONNECTION_H
#define ASYNC_CLIENT_QUEUE_SERVER_CLIENTS_CONNECTION_H

#include "../abstract_connection.h"

class clients_connection : public AbstractConnection {
public:
    clients_connection(boost::asio::io_context& io_context, const tcp::resolver::results_type& endpoints);

    void write(const std::string& msg);
    void close();

private:

    void handle_connect(const boost::system::error_code& error);
    void handle_read(const boost::system::error_code& error) override;
    void do_write(std::string msg);
    void handle_write(const boost::system::error_code& error) override;

private:
    boost::asio::io_context& io_context_;
};


#endif //ASYNC_CLIENT_QUEUE_SERVER_CLIENTS_CONNECTION_H
