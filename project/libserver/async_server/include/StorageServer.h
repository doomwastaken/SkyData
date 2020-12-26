//
// Created by denis on 09.12.2020.
//

#ifndef ASYNC_CLIENT_QUEUE_SERVER_STORAGESERVER_H
#define ASYNC_CLIENT_QUEUE_SERVER_STORAGESERVER_H

#include "AbstractServer.h"

class StorageServer : public AbstractServer {
public:
    StorageServer(boost::asio::io_context& io_context,
                  const boost::asio::ip::tcp::endpoint& endpoint);

    void start_accept() override;
    void deliver_for_all(std::string msg) override;
    void on_read_message(char* msg) override;
};

#endif //ASYNC_CLIENT_QUEUE_SERVER_STORAGESERVER_H
