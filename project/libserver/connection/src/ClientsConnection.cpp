#include "ClientsConnection.h"

ClientsConnection::ClientsConnection(
        boost::asio::io_context& io_context,
        const tcp::resolver::results_type& endpoint):
            AbstractConnection(io_context),
            m_io_context(io_context), endpoint(endpoint) {
    boost::asio::async_connect(m_socket, endpoint,
                               boost::bind(
                                            &ClientsConnection::handle_connect,
                                            this,
                                            boost::asio::placeholders::error));
}

void ClientsConnection::write(const std::string& msg) {
    boost::asio::post(m_io_context,
                      boost::bind(&ClientsConnection::do_write, this, msg));
}

void ClientsConnection::close() {
    boost::asio::post(m_io_context,
                      boost::bind(&ClientsConnection::do_close, this));
}

void ClientsConnection::handle_connect(const boost::system::error_code &error) {
    if (!error) {
        boost::asio::async_read(m_socket,
                                boost::asio::buffer(m_read_msg),
                                [&] (const boost::system::error_code & err, size_t bytes)
                                    { return std::find(m_read_msg, m_read_msg + bytes, '\n') < m_read_msg + bytes; },
                                boost::bind(&ClientsConnection::handle_read,
                                                    this,
                                                    boost::asio::placeholders::error));
    } else {
        std::cerr << "ERROR: ClientsConnection::handle_connect" << std::endl;
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(1000ms);
        boost::asio::async_connect(m_socket, endpoint,
                                   boost::bind(
                                           &ClientsConnection::handle_connect,
                                           this,
                                           boost::asio::placeholders::error));
    }
}

// TODO: Implement logic of file refresh!
void ClientsConnection::handle_read(const boost::system::error_code &error) {
    if (!error) {
        for (char i : m_read_msg) {
            if (i == '\n') { break ;}
            std::cout << i;
        }
        std::cout << std::endl;
        boost::asio::async_read(m_socket,
                                boost::asio::buffer(m_read_msg),
                                [&] (const boost::system::error_code & err, size_t bytes)
                                { return std::find(m_read_msg, m_read_msg + bytes, '\n') < m_read_msg + bytes; },
                                boost::bind(
                                            &ClientsConnection::handle_read,
                                            this,
                                            boost::asio::placeholders::error));
    }
    else { do_close(); }
}

void ClientsConnection::do_write(std::string msg) {
    bool write_in_progress = !m_write_msgs.empty();
    m_write_msgs.push_back(msg);
    if (!write_in_progress) {
        boost::asio::async_write(m_socket,
                                 boost::asio::buffer(m_write_msgs.front().data(), m_write_msgs.front().length()),
                                 boost::bind(&ClientsConnection::handle_write, this,
                                             boost::asio::placeholders::error));
    }
}

void ClientsConnection::handle_write(const boost::system::error_code &error) {
    if (!error) {
        m_write_msgs.pop_front();
        if (!m_write_msgs.empty()) {
            boost::asio::async_write(m_socket,
                                     boost::asio::buffer(m_write_msgs.front().data(),
                                                         m_write_msgs.front().length()),
                                     boost::bind(&ClientsConnection::handle_write, this,
                                                 boost::asio::placeholders::error));
        }
    }
    else {
        do_close();
    }
}
