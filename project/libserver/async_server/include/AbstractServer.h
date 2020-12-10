#ifndef ASYNC_CLIENT_QUEUE_SERVER_ABSTRACT_SERVER_H
#define ASYNC_CLIENT_QUEUE_SERVER_ABSTRACT_SERVER_H

#include <cstdlib>
#include <deque>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>


#include "Message.h"
#include "ServerConnection.h"

class AbstractServer{
public:
    AbstractServer(boost::asio::io_context& io_context, const boost::asio::ip::tcp::endpoint& endpoint):
        m_io_context(io_context),
        m_acceptor(io_context, endpoint)
        {}

    virtual void start_accept() = 0;

    void handle_accept(boost::shared_ptr<ServerConnection> session,
                       const boost::system::error_code& error) {
        if (!error) {
            m_connections.insert(session);
            session->start();
        }

        start_accept();
    }

    virtual void deliver_for_all(char* msg) = 0;

    virtual void on_readed_message(char* msg) = 0;

protected:
    boost::asio::io_context& m_io_context;
    boost::asio::ip::tcp::acceptor m_acceptor;
    std::set<boost::shared_ptr<ServerConnection>> m_connections;
    std::deque<std::string> m_messages_to_send;
};

#endif //ASYNC_CLIENT_QUEUE_SERVER_ABSTRACT_SERVER_H
