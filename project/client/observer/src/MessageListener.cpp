#include "MessageListener.h"
#include "ClientsConnection.h"


MessageListener::MessageListener(boost::asio::io_context &io_context,
                                 const boost::asio::ip::basic_resolver<tcp, boost::asio::executor>::results_type &endpoint) :
                                 //boost::asio::io_context& io_context_storage, const tcp::resolver::results_type& endpoint_storage) :
                                 cl_con(io_context, endpoint) { ; }


