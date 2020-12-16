#include "ServerConnection.h"
#include "AbstractServer.h"

<<<<<<< HEAD

=======
>>>>>>> development
ServerConnection::ServerConnection(boost::asio::io_context& io_context,
                                   std::shared_ptr<AbstractServer> srvr):
    AbstractConnection(io_context),
    m_server_ptr(srvr)
    {}

boost::asio::ip::tcp::socket& ServerConnection::socket() {
    return m_socket;
}

void ServerConnection::start() {
    boost::asio::async_read(m_socket,
                            boost::asio::buffer(m_read_msg),
                            [&] (const boost::system::error_code & err, size_t bytes)
<<<<<<< HEAD
                            { return std::find(m_read_msg, m_read_msg + bytes, '\n') < m_read_msg + bytes; },
=======
                            { return (std::find(m_read_msg, m_read_msg + bytes, '\n') < m_read_msg + bytes ||
                                      std::find(m_read_msg, m_read_msg + bytes, EOF) < m_read_msg + bytes); },
>>>>>>> development
                            boost::bind(
                                    &ServerConnection::handle_read,
                                    shared_from_this(),
                                    boost::asio::placeholders::error));
}

void ServerConnection::handle_read(const boost::system::error_code& error) {
    if (!error) {
<<<<<<< HEAD
        for (const char& i : m_read_msg) {
            if (i == '\n') { break; }
            std::cout << i;
        }
        std::cout << std::endl;
=======
        int i = 0;
        for (; m_read_msg[i] != '\n'; i++) {
//            std::cout << m_read_msg[i];
        }
//        std::cout << std::endl;

        std::stringstream str;
        str << std::string(m_read_msg, i);
//        std::cout << str.str() << std::endl;
        boost::archive::text_iarchive iarch(str);
        Message msg;
        iarch >> msg;
        if (this->id.empty()) {
            this->id = msg.user.user_name + msg.user.devise.device_name;
        }
>>>>>>> development

        m_server_ptr->on_readed_message(m_read_msg);

        boost::asio::async_read(m_socket,
                                boost::asio::buffer(m_read_msg),
                                [&] (const boost::system::error_code & err, size_t bytes)
<<<<<<< HEAD
                                { return std::find(m_read_msg, m_read_msg + bytes, '\n') < m_read_msg + bytes; },
=======
                                {
                                    return (std::find(m_read_msg, m_read_msg + bytes, '\n') < m_read_msg + bytes); },// ||
//                                            std::find(m_read_msg, m_read_msg + bytes, EOF) < m_read_msg + bytes); },
>>>>>>> development
                                boost::bind(
                                            &ServerConnection::handle_read,
                                            shared_from_this(),
                                            boost::asio::placeholders::error));
    } else {
        std::cerr << "Fault";
    }
}

<<<<<<< HEAD
void ServerConnection::deliver(char* msg) {
=======
void ServerConnection::deliver(std::string msg) {
>>>>>>> development
    bool write_in_progress = !m_write_msgs.empty();
    m_write_msgs.emplace_back(msg);
    if (!write_in_progress) {
        boost::asio::async_write(m_socket,
                                 boost::asio::buffer(m_write_msgs.front().data(),
                                                     m_write_msgs.front().length()),
                                 boost::bind(
                                            &ServerConnection::handle_write,
                                            shared_from_this(),
                                            boost::asio::placeholders::error));
    }
}

void ServerConnection::handle_write(const boost::system::error_code& error) {
    if (!error) {
<<<<<<< HEAD
=======
        last_success_message_sended = m_write_msgs.front();
>>>>>>> development
        m_write_msgs.pop_front();
        if (!m_write_msgs.empty()) {
            boost::asio::async_write(m_socket,
                                     boost::asio::buffer(m_write_msgs.front().data(),
                                                         m_write_msgs.front().length()),
                                     boost::bind(
                                                &ServerConnection::handle_write,
                                                shared_from_this(),
                                                boost::asio::placeholders::error));
        }
    } else {
<<<<<<< HEAD
        std::cerr << "Error handle_write! " << error.message();
=======
        m_server_ptr->remove_connection(this->id, m_write_msgs.front());
        std::cerr << "Error handle_write! " << error.message();
        m_write_msgs.pop_front();
>>>>>>> development
    }
}