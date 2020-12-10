#include "MessageListener.h"
#include "ClientsConnection.h"


MessageListener::MessageListener(boost::asio::io_context &io_context,
                                 const boost::asio::ip::basic_resolver<tcp, boost::asio::executor>::results_type &endpoint) :
                                 cl_con(io_context, endpoint) {

}


