//
// Created by denis on 03.12.2020.
//

#ifndef ASYNC_CLIENT_QUEUE_SERVER_BACKEND_CONNECTION_H
#define ASYNC_CLIENT_QUEUE_SERVER_BACKEND_CONNECTION_H

#include "../abstract_connection.h"
#include "../../server/middle_end/middle_end.h"

class middle_end;

class ToBackendConnection : public AbstractConnection{
public:
    ToBackendConnection(boost::asio::io_context& io_context, const tcp::resolver::results_type& endpoints);
    void write(std::string msg);
    void set_owner_server(std::shared_ptr<middle_end> serv);
    void close();

private:
    void handle_connect(const boost::system::error_code& error);
    virtual void handle_read(const boost::system::error_code& error) override;
    void do_write(std::string msg);
    virtual void handle_write(const boost::system::error_code& error) override;

private:
    boost::asio::io_context& io_context_;
    std::shared_ptr<middle_end> server;
};


#endif //ASYNC_CLIENT_QUEUE_SERVER_BACKEND_CONNECTION_H
