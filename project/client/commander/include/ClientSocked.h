#ifndef PROJECT_CLIENTSOCKED_H
#define PROJECT_CLIENTSOCKED_H

#include <boost/asio.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <string>
#include <Message.h>

namespace as = boost::asio;

class ClientSocked {
public:
    ClientSocked(std::string &host, int post);
    ~ClientSocked();

    int connection();
    int send();
    int pop();
    void close() const;

    void serialize(Message &message);
    std::shared_ptr<Message> deserialize();

//protected:
    std::string buf_send;
    std::string buf_pop;

private:
    as::io_service m_io_service;
    as::ip::tcp::socket m_socket;
private:
    std::string m_host;
    int m_port;
    int m_timeout;

};

#endif //PROJECT_CLIENTSOCKED_H
