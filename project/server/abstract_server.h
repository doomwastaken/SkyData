//
// Created by denis on 03.12.2020.
//

#ifndef ASYNC_CLIENT_QUEUE_SERVER_ABSTRACT_SERVER_H

#include <cstdlib>
#include <deque>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include "../common/Message.h"
#include "../connection/server_connection/server_connection.h"

class abstract_server{
public:
    abstract_server(boost::asio::io_context& io_context, const boost::asio::ip::tcp::endpoint& endpoint)
            : io_context_(io_context),
              acceptor_(io_context, endpoint) { ; }

    virtual void start_accept() = 0;

    void handle_accept(boost::shared_ptr<server_connection> connection,
                       const boost::system::error_code& error) {
        if (!error)
        {
            connections.insert(connection);
            connection->start();
        }

        start_accept();
    }

    virtual void deliver_for_all(char* msg) = 0;

    virtual void on_readed_message(char* msg) = 0;

protected:
    boost::asio::io_context& io_context_;
    boost::asio::ip::tcp::acceptor acceptor_;
    std::set<boost::shared_ptr<server_connection>> connections;
    std::deque<std::string> messages_to_send;
};
#define ASYNC_CLIENT_QUEUE_SERVER_ABSTRACT_SERVER_H

#endif //ASYNC_CLIENT_QUEUE_SERVER_ABSTRACT_SERVER_H
