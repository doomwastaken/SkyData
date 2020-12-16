#ifndef ASYNC_CLIENT_QUEUE_SERVER_MIDDLEEND_H
#define ASYNC_CLIENT_QUEUE_SERVER_MIDDLEEND_H

#include "AbstractServer.h"
#include "ToBackendConnection.h"
#include "ServerConnection.h"

class ToBackendConnection;

class MiddleEnd : public AbstractServer{
public:
    MiddleEnd(boost::asio::io_context& io_context,
              const boost::asio::ip::tcp::endpoint& endpoint);


    void set_client_for_backend(std::shared_ptr<ToBackendConnection>);

    virtual void start_accept() override;

    virtual void deliver_for_all(char* msg) override;

<<<<<<< HEAD:project/libserver/async_server/include/MiddleEnd.h
=======
    void send_message_if_connected(const std::string& messageID);

>>>>>>> development:project/server/middle_end/middle_end.h
    virtual void on_readed_message(char* msg) override;

    void write_to_backend(char* msg);

<<<<<<< HEAD:project/libserver/async_server/include/MiddleEnd.h
=======
    void remove_connection(std::string id);

>>>>>>> development:project/server/middle_end/middle_end.h
    virtual ~MiddleEnd() = default;

private:
    std::shared_ptr<ToBackendConnection> m_backend;
};


#endif //ASYNC_CLIENT_QUEUE_SERVER_MIDDLEEND_H
