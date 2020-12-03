//
// Created by denis on 03.12.2020.
//

#ifndef ASYNC_CLIENT_QUEUE_SERVER_BACKEND_SERVER_H
#define ASYNC_CLIENT_QUEUE_SERVER_BACKEND_SERVER_H

#include "../abstract_server.h"

class backend_server : public abstract_server {
public:

    backend_server(boost::asio::io_context& io_context, const boost::asio::ip::tcp::endpoint& endpoint);

    virtual void start_accept() override;

    virtual void on_readed_message(char* msg) override;

private:
    virtual void deliver_for_all(char* msg) override;
};


#endif //ASYNC_CLIENT_QUEUE_SERVER_BACKEND_SERVER_H
