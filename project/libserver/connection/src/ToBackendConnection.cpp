#include "ToBackendConnection.h"

// FIXME: remove this
void print_mes_mid(Message &message) {
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

ToBackendConnection::ToBackendConnection(boost::asio::io_context& io_context,
                                       const tcp::resolver::results_type& endpoint):
                                            AbstractConnection(io_context),
                                            m_io_context(io_context), endpoint(endpoint) {
    boost::asio::async_connect(m_socket, endpoint,
                               boost::bind(
                                            &ToBackendConnection::handle_connect,
                                            this,
                                            boost::asio::placeholders::error));
}

void ToBackendConnection::set_owner_server(std::shared_ptr<MiddleEnd> serv) {
    m_server = serv;
}


void ToBackendConnection::write(const std::string& msg) {
    boost::asio::post(m_io_context,
                      boost::bind(&ToBackendConnection::do_write, this, msg));
}

void ToBackendConnection::reconnect() {
    m_socket =  boost::asio::ip::tcp::socket(m_io_context);
    boost::asio::async_connect(m_socket, endpoint,
                               boost::bind(
                                       &ToBackendConnection::handle_connect,
                                       this,
                                       boost::asio::placeholders::error));
}

void ToBackendConnection::close() {
    boost::asio::post(m_io_context,
                      boost::bind(&ToBackendConnection::do_close, this));
}

void ToBackendConnection::handle_connect(const boost::system::error_code& error) {
    if (!error) {
        isConnected = true;
        // This case will happen only if if will get in error while async_write or
        // the messages queue is not empty!
        if (operation == AbstractConnection::last_unsuccess_operation::WRITE ||
            !m_write_msgs.empty()) {
            // Just trying to write the same message before the failure in connection
            write();
        }
        // By default just trying to read
        else if (operation == AbstractConnection::last_unsuccess_operation::READ) {
            boost::asio::async_read(m_socket,
                                    boost::asio::buffer(m_read_msg),
                                    [&](const boost::system::error_code &err, size_t bytes) {
                                        return std::find(m_read_msg, m_read_msg + bytes, '\b') < m_read_msg + bytes;
                                    },
                                    boost::bind(&ToBackendConnection::handle_read,
                                                this,
                                                boost::asio::placeholders::error));
        }
    } else {
        isConnected = false;
        std::cerr << "ERROR: to_backend_connection::handle_connect" << std::endl;
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(1000ms);
        boost::asio::async_connect(m_socket, endpoint,
                                   boost::bind(
                                           &ToBackendConnection::handle_connect,
                                           this,
                                           boost::asio::placeholders::error));
    }
}

//TODO: OPTIMIZATION
void ToBackendConnection::handle_read(const boost::system::error_code& error) {
    if (!error) {
        try {
            int i = 0;
            for (; m_read_msg[i] != '\b'; i++) { ; }

            //DONE: IMPLEMENTATION OF QUEUE LOGIC
            // Firstly deserialize message
            std::string str_mes = m_read_msg;
            std::stringstream str(str_mes);
            boost::archive::text_iarchive iarch(str);
            Message msg;
            iarch >> msg;

            std::cout << "Middle: " << std::endl;
            print_mes_mid(msg);

            // Secondly push message to the users queue
            QueueManager::queue_manager().push_to_client_queue(std::string(m_read_msg),
                                                               std::string(msg.user.user_name
                                                                           + msg.user.devise.device_name));
            std::cout << "IN ToBackendConnection::handle_read:: Messages amount for "
                      << std::string(msg.user.user_name + msg.user.devise.device_name)
                      << ": " << QueueManager::queue_manager().get_client_messages_amount(std::string(msg.user.user_name
                                                                                                      +
                                                                                                      msg.user.devise.device_name))
                      << std::endl << std::endl;

            // Then call the send method to server.
            std::cout << msg.user.user_name << " " << msg.user.devise.device_name << std::endl;
            try {
                m_server->send_message_if_connected(std::string(msg.user.user_name + msg.user.devise.device_name));
            } catch (std::exception &err) {
                std::cout << err.what();
            }
            std::cout << "send " << std::endl;
            // Continue async_reading
            boost::asio::async_read(m_socket,
                                    boost::asio::buffer(m_read_msg),
                                    [&](const boost::system::error_code &err, size_t bytes) {
                                        return std::find(m_read_msg, m_read_msg + bytes, '\b') < m_read_msg + bytes;
                                    },
                                    boost::bind(
                                            &ToBackendConnection::handle_read,
                                            this,
                                            boost::asio::placeholders::error));
        } catch (std::exception& err) {
            std::cerr << err.what();
        }
    }
    else {
        isConnected = false;
        std::cerr << "ERROR: ToBackendConnection::handle_read" << std::endl;
        std::cerr << "Trying to reconnect!" << std::endl;
        operation = AbstractConnection::last_unsuccess_operation::READ;
        boost::asio::async_connect(m_socket, endpoint,
                                   boost::bind(
                                           &ToBackendConnection::handle_connect,
                                           this,
                                           boost::asio::placeholders::error));
    }
}

void ToBackendConnection::do_write(const std::string& msg) {
    bool write_in_progress = !m_write_msgs.empty();
    if (!msg.empty()) { m_write_msgs.push_back(msg); }
    if (!write_in_progress && isConnected) {
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
        // DOESN`T WORK RIGHT NOW!
        isConnected = false;
        std::cerr << "ERROR: ToBackendConnection::handle_write" << std::endl;
        std::cerr << "Trying to reconnect!" << std::endl;
        operation = AbstractConnection::last_unsuccess_operation::WRITE;
        m_io_context.reset();
        m_socket.close();
        boost::asio::post(m_io_context,
                          boost::bind(&ToBackendConnection::reconnect, this));
    }
}
