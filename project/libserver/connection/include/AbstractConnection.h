#ifndef ASYNC_CLIENT_QUEUE_SERVER_ABSTRACT_CONNECTION_H
#define ASYNC_CLIENT_QUEUE_SERVER_ABSTRACT_CONNECTION_H

#include <cstdlib>
#include <deque>
#include <iostream>
#include <chrono>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include "Message.h"

using boost::asio::ip::tcp;
typedef std::deque<std::string> chat_message_queue;

class AbstractConnection
{
public:
    AbstractConnection(boost::asio::io_context& io_context) : m_socket(io_context), operation(READ), id("") { ; }

//    virtual void write(const std::string& msg) = 0;

//    virtual void close() = 0;

    std::string id;

    std::string last_success_message_sended;

protected:

    virtual void handle_read(const boost::system::error_code& error) = 0;

    virtual void handle_write(const boost::system::error_code& error) = 0;

    virtual void do_close() {
        boost::system::error_code err;
        m_socket.close(err);
    };

//    virtual void handle_connect(const boost::system::error_code& error) = 0;

//    virtual void do_write(std::string msg) = 0;


    // Identifier for message sending

    enum last_unsuccess_operation {
        READ,
        WRITE,
    };

protected:
    boost::asio::ip::tcp::socket m_socket;
    char m_read_msg[1024];
    std::deque<std::string> m_write_msgs;
    last_unsuccess_operation operation;
    bool isConnected;
};


#endif //ASYNC_CLIENT_QUEUE_SERVER_ABSTRACT_CONNECTION_H
