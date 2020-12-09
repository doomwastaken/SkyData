#ifndef ASYNC_CLIENT_QUEUE_SERVER_BACKEND_SERVER_H
#define ASYNC_CLIENT_QUEUE_SERVER_BACKEND_SERVER_H

#include "AbstractServer.h"

class BackendServer : public AbstractServer {
public:

    BackendServer(boost::asio::io_context& io_context,
                  const boost::asio::ip::tcp::endpoint& endpoint);

    virtual void start_accept() override;

    virtual void on_readed_message(char* msg) override;

    virtual ~BackendServer() = default;

private:
    virtual void deliver_for_all(char* msg) override;
};


#endif //ASYNC_CLIENT_QUEUE_SERVER_BACKEND_SERVER_H
