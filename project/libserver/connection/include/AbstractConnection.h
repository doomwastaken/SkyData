#ifndef ASYNC_CLIENT_QUEUE_SERVER_ABSTRACT_CONNECTION_H
#define ASYNC_CLIENT_QUEUE_SERVER_ABSTRACT_CONNECTION_H

#include <cstdlib>
#include <deque>
#include <iostream>
#include <chrono>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>

#include "Message.h"

using boost::asio::ip::tcp;
typedef std::deque<std::string> chat_message_queue;

class AbstractConnection
{
public:
    AbstractConnection(boost::asio::io_context& io_context) : m_socket(io_context) { ; }

//    virtual void write(const std::string& msg) = 0;

//    virtual void close() = 0;

protected:

    virtual void handle_read(const boost::system::error_code& error) = 0;

    virtual void handle_write(const boost::system::error_code& error) = 0;

    virtual void do_close() { m_socket.close(); };

//    virtual void handle_connect(const boost::system::error_code& error) = 0;

//    virtual void do_write(std::string msg) = 0;

protected:
    boost::asio::ip::tcp::socket m_socket;
    char m_read_msg[1024];
    std::deque<std::string> m_write_msgs;
};


#endif //ASYNC_CLIENT_QUEUE_SERVER_ABSTRACT_CONNECTION_H
