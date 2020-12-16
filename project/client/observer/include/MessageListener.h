#ifndef PROJECT_MESSAGELISTENER_H
#define PROJECT_MESSAGELISTENER_H
#include "iostream"
#include "Message.h"

#include "ClientsConnection.h"

class MessageListener {




public:
    MessageListener(boost::asio::io_context& io_context, const tcp::resolver::results_type& endpoint);
    ClientsConnection cl_con;

};

#endif //PROJECT_MESSAGELISTENER_H
