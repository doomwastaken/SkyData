//
// Created by denis on 03.12.2020.
//

#ifndef ASYNC_CLIENT_QUEUE_SERVER_MIDDLEEND_H
#define ASYNC_CLIENT_QUEUE_SERVER_MIDDLEEND_H

#include "../abstract_server.h"
#include "../../connection/to_backend_connection/to_backend_connection.h"
#include "../../connection/server_connection/server_connection.h"

class ToBackendConnection;

class middle_end : public abstract_server{
public:
    middle_end(boost::asio::io_context& io_context,
                const boost::asio::ip::tcp::endpoint& endpoint);


    void set_client_for_backend(std::shared_ptr<ToBackendConnection>);

    virtual void start_accept() override;
    virtual void deliver_for_all(char* msg) override;
    virtual void on_readed_message(char* msg) override;

    void write_to_backend(char* msg);

private:
    std::shared_ptr<ToBackendConnection> backend;
};


#endif //ASYNC_CLIENT_QUEUE_SERVER_MIDDLEEND_H
