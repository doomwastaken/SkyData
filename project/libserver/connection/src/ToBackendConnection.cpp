#include "ToBackendConnection.h"

ToBackendConnection::ToBackendConnection(boost::asio::io_context& io_context,
                                       const tcp::resolver::results_type& endpoints):
                                            AbstractConnection(io_context),
                                            m_io_context(io_context) {
    boost::asio::async_connect(m_socket, endpoints,
                               boost::bind(
                                            &ToBackendConnection::handle_connect,
                                            this,
                                            boost::asio::placeholders::error));
}

void ToBackendConnection::set_owner_server(std::shared_ptr<MiddleEnd> serv) {
    m_server = serv;
}

void ToBackendConnection::write(std::string msg) {
    boost::asio::post(m_io_context,
                      boost::bind(&ToBackendConnection::do_write, this, msg));
}

void ToBackendConnection::close() {
    boost::asio::post(m_io_context,
                      boost::bind(&ToBackendConnection::do_close, this));
}

void ToBackendConnection::handle_connect(const boost::system::error_code& error) {
    if (!error) {
        boost::asio::async_read(m_socket,
                                boost::asio::buffer(m_read_msg),
                                [&] (const boost::system::error_code & err, size_t bytes)
                                { return std::find(m_read_msg, m_read_msg + bytes, '\n') < m_read_msg + bytes; },
                                boost::bind(
                                            &ToBackendConnection::handle_read,
                                            this,
                                            boost::asio::placeholders::error));
    } else {
        std::cerr << "ERROR: to_backend_connection::handle_connect";
    }
}

void ToBackendConnection::handle_read(const boost::system::error_code& error) {
    if (!error) {
        for (int i = 0; i < 1024; i++) {
            if (m_read_msg[i] == '\n') { break ;}
            std::cout << m_read_msg[i];
        }
        std::cout << std::endl;

        //TODO: REMOVE COMMENT
        m_server->deliver_for_all(m_read_msg);
        boost::asio::async_read(m_socket,
                                boost::asio::buffer(m_read_msg),
                                [&] (const boost::system::error_code & err, size_t bytes)
                                { return std::find(m_read_msg, m_read_msg + bytes, '\n') < m_read_msg + bytes; },
                                boost::bind(
                                            &ToBackendConnection::handle_read,
                                            this,
                                            boost::asio::placeholders::error));
    }
    else {
        do_close();
    }
}

void ToBackendConnection::do_write(std::string msg) {
    bool write_in_progress = !m_write_msgs.empty();
    m_write_msgs.push_back(msg);
    if (!write_in_progress) {
        boost::asio::async_write(m_socket,
                                 boost::asio::buffer(m_write_msgs.front().data(),
                                                     m_write_msgs.front().length()),
                                 boost::bind(
                                                &ToBackendConnection::handle_write,
                                                this,
                                                boost::asio::placeholders::error));
    }
}

void ToBackendConnection::handle_write(const boost::system::error_code& error) {
    if (!error) {
        m_write_msgs.pop_front();
        if (!m_write_msgs.empty()) {
            boost::asio::async_write(m_socket,
                                     boost::asio::buffer(m_write_msgs.front().data(),
                                                         m_write_msgs.front().length()),
                                     boost::bind(
                                                    &ToBackendConnection::handle_write,
                                                    this,
                                                    boost::asio::placeholders::error));
        }
    }
    else {
        do_close();
    }
}
