#include "ClientsConnection.h"

// FIXME: remove this
void print_mes(Message &message) {
    std::cout << "user name: " << message.user.user_name << std::endl;
    std::cout << "user email: " << message.user.email << std::endl;
    std::cout << "version: " << message.version << std::endl;
    std::cout << "times modified: " << message.times_modified << std::endl;
    std::cout << "file name: " << message.file_name << std::endl;
    std::cout << "file extention: " << message.file_extension<< std::endl;
    std::cout << "file size: " << message.file_size << std::endl;
    std::cout << "file path: " << message.file_path << std::endl;
    std::cout << "devise name: " << message.user.devise.device_name << std::endl;
    std::cout << "sync folder: " << message.user.devise.sync_folder << std::endl;
    std::cout << "quota limit: " << message.user.quota_limit << std::endl;
}

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

void ClientsConnection::write(const Message& msg) {
    boost::asio::post(m_io_context,
                      boost::bind(&ClientsConnection::do_write, this, msg, false));
}

void ClientsConnection::close() {
    boost::asio::post(m_io_context,
                      boost::bind(&ClientsConnection::do_close, this));

    using namespace std::chrono_literals;
    std::this_thread::sleep_for(2000ms);
    m_io_context.stop();
}

void ClientsConnection::handle_connect(const boost::system::error_code &error) {
    if (!error) {
        // By default just trying to read
        boost::asio::async_read(m_socket,
                                boost::asio::buffer(m_read_msg),
                                [&](const boost::system::error_code &err, size_t bytes) {
                                    return std::find(m_read_msg, m_read_msg + bytes, '\b') < m_read_msg + bytes;
                                },
                                boost::bind(&ClientsConnection::handle_read,
                                            this,
                                            boost::asio::placeholders::error));
    } else {
        std::cerr << "ERROR: ClientsConnection::handle_connect" << std::endl;
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(1000ms);
        // Trying to reconnect!
        boost::asio::async_connect(m_socket, endpoint,
                                   boost::bind(
                                           &ClientsConnection::handle_connect,
                                           this,
                                           boost::asio::placeholders::error));
    }
}

// TODO: Implement logic of downloading from storage server!
void ClientsConnection::handle_read(const boost::system::error_code &error) {
    if (!error) {
        std::string str_mes = m_read_msg;
        std::stringstream str(str_mes);
        boost::archive::text_iarchive iarch(str);
        Message msg;
        iarch >> msg;

        std::cout << "Client: " << std::endl;

        print_mes(msg);

        // async reading again
        boost::asio::async_read(m_socket,
                                boost::asio::buffer(m_read_msg),
                                [&] (const boost::system::error_code & err, size_t bytes)
                                { return std::find(m_read_msg, m_read_msg + bytes, '\b') < m_read_msg + bytes; },
                                boost::bind(
                                            &ClientsConnection::handle_read,
                                            this,
                                            boost::asio::placeholders::error));
    }
    else { do_close(); }
}

void ClientsConnection::do_write(const Message& msg, bool continue_writing) {
    bool write_in_progress = !m_write_msgs.empty();
    // Serialize our Message struct to string
    std::stringstream str;
    boost::archive::text_oarchive oarch(str);
    oarch << msg;
    // The "\b" is a SEPARATOR FOR MESSAGES!
    m_write_msgs.push_back(str.str() + "\b");
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
        std::cerr << "ERROR: ClientsConnection::handle_write" << std::endl;
    }
}
