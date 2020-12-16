#ifndef ASYNC_CLIENT_QUEUE_SERVER_BACKEND_CONNECTION_H
#define ASYNC_CLIENT_QUEUE_SERVER_BACKEND_CONNECTION_H

#include "AbstractConnection.h"
#include "MiddleEnd.h"
<<<<<<< HEAD:project/libserver/connection/include/ToBackendConnection.h
=======
#include "QueueManager.h"
>>>>>>> development:project/connection/to_backend_connection/to_backend_connection.h

class MiddleEnd;

class ToBackendConnection : public AbstractConnection{
public:
    ToBackendConnection(boost::asio::io_context& io_context, const tcp::resolver::results_type& endpoint);

<<<<<<< HEAD:project/libserver/connection/include/ToBackendConnection.h
    void write(std::string msg);
=======
    void write(const std::string& msg = "");

    void reconnect();
>>>>>>> development:project/connection/to_backend_connection/to_backend_connection.h

    void set_owner_server(std::shared_ptr<MiddleEnd> serv);

    void close();

    virtual ~ToBackendConnection() = default;

private:
    void handle_connect(const boost::system::error_code& error);

    virtual void handle_read(const boost::system::error_code& error) override;

<<<<<<< HEAD:project/libserver/connection/include/ToBackendConnection.h
    void do_write(std::string msg);
=======
    void do_write(const std::string& msg = "");
>>>>>>> development:project/connection/to_backend_connection/to_backend_connection.h

    virtual void handle_write(const boost::system::error_code& error) override;

private:
    boost::asio::io_context& m_io_context;
    std::shared_ptr<MiddleEnd> m_server;
    tcp::resolver::results_type endpoint;
};


#endif //ASYNC_CLIENT_QUEUE_SERVER_BACKEND_CONNECTION_H
