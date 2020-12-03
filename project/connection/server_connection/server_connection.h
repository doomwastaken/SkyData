//
// Created by denis on 03.12.2020.
//

#ifndef ASYNC_CLIENT_QUEUE_SERVER_SERVER_CONNECTION_H
#define ASYNC_CLIENT_QUEUE_SERVER_SERVER_CONNECTION_H


#include "../abstract_connection.h"

class abstract_server;

class server_connection : public AbstractConnection, public boost::enable_shared_from_this<server_connection> {
public:
    server_connection(boost::asio::io_context& io_context, std::shared_ptr<abstract_server> srvr);

    boost::asio::ip::tcp::socket& socket();

//    'write' 'close' 'handle_connect' 'do_write'
    void start();
    void handle_read(const boost::system::error_code& error) override;
    void deliver(char* msg);
    void handle_write(const boost::system::error_code& error) override;

private:
    std::shared_ptr<abstract_server> server_ptr;
};


#endif //ASYNC_CLIENT_QUEUE_SERVER_SERVER_CONNECTION_H
