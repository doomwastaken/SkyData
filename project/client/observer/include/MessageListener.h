#ifndef PROJECT_MESSAGELISTENER_H
#define PROJECT_MESSAGELISTENER_H
#include "iostream"
#include "Message.h"

#include "ClientsConnection.h"
#include "ClientToStorageConnection.h"

class MessageListener {




public:
    MessageListener(boost::asio::io_context& io_context, const tcp::resolver::results_type& endpoint);//,
                    //boost::asio::io_context& io_context_storage, const tcp::resolver::results_type& endpoint_storage);
    ClientsConnection cl_con;
    //ClientToStorageConnection storage_connection;

};

#endif //PROJECT_MESSAGELISTENER_H
