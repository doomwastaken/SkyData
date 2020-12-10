#ifndef PROJECT_MESSAGELISTENER_H
#define PROJECT_MESSAGELISTENER_H
#include "iostream"
#include "Message.h"

#include "ClientsConnection.h"

class MessageListener {
    ClientsConnection cl_con;



public:
    MessageListener(boost::asio::io_context& io_context, const tcp::resolver::results_type& endpoint);

};

#endif //PROJECT_MESSAGELISTENER_H
