//
// Created by denis on 03.12.2020.
//

#ifndef ASYNC_CLIENT_QUEUE_SERVER_ABSTRACT_CONNECTION_H

#include <cstdlib>
#include <deque>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include "../common/Message.h"

using boost::asio::ip::tcp;
typedef std::deque<std::string> chat_message_queue;

class AbstractConnection
{
public:
    AbstractConnection(boost::asio::io_context& io_context) : socket_(io_context) { ; }

//    virtual void write(const std::string& msg) = 0;
//    virtual void close() = 0;

protected:

//    virtual void handle_connect(const boost::system::error_code& error) = 0;
    virtual void handle_read(const boost::system::error_code& error) = 0;
//    virtual void do_write(std::string msg) = 0;
    virtual void handle_write(const boost::system::error_code& error) = 0;
    virtual void do_close() { socket_.close(); };

protected:
    boost::asio::ip::tcp::socket socket_;
    char read_msg_[1024];
    std::deque<std::string> write_msgs_;
};

#define ASYNC_CLIENT_QUEUE_SERVER_ABSTRACT_CONNECTION_H

#endif //ASYNC_CLIENT_QUEUE_SERVER_ABSTRACT_CONNECTION_H
