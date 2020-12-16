#include "ToBackendConnection.h"

<<<<<<< HEAD
=======
// TODO: RECONNECT TO BACKEND SERVER!
>>>>>>> development
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

<<<<<<< HEAD
void ToBackendConnection::write(std::string msg) {
=======
void ToBackendConnection::write(const std::string& msg) {
>>>>>>> development
    boost::asio::post(m_io_context,
                      boost::bind(&ToBackendConnection::do_write, this, msg));
}

<<<<<<< HEAD
=======
void ToBackendConnection::reconnect() {
    m_socket =  boost::asio::ip::tcp::socket(m_io_context);
    boost::asio::async_connect(m_socket, endpoint,
                               boost::bind(
                                       &ToBackendConnection::handle_connect,
                                       this,
                                       boost::asio::placeholders::error));
}

>>>>>>> development
void ToBackendConnection::close() {
    boost::asio::post(m_io_context,
                      boost::bind(&ToBackendConnection::do_close, this));
}

void ToBackendConnection::handle_connect(const boost::system::error_code& error) {
    if (!error) {
<<<<<<< HEAD
        boost::asio::async_read(m_socket,
                                boost::asio::buffer(m_read_msg),
                                [&] (const boost::system::error_code & err, size_t bytes)
                                { return std::find(m_read_msg, m_read_msg + bytes, '\n') < m_read_msg + bytes; },
                                boost::bind(
                                            &ToBackendConnection::handle_read,
                                            this,
                                            boost::asio::placeholders::error));
    } else {
=======
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
                                        return std::find(m_read_msg, m_read_msg + bytes, '\n') < m_read_msg + bytes;
                                    },
                                    boost::bind(&ToBackendConnection::handle_read,
                                                this,
                                                boost::asio::placeholders::error));
        }
    } else {
        isConnected = false;
>>>>>>> development
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

<<<<<<< HEAD
void ToBackendConnection::handle_read(const boost::system::error_code& error) {
    if (!error) {
        for (int i = 0; i < 1024; i++) {
            if (m_read_msg[i] == '\n') { break ;}
            std::cout << m_read_msg[i];
        }
        std::cout << std::endl;

        //TODO: REMOVE COMMENT
        m_server->deliver_for_all(m_read_msg);
=======
//TODO: OPTIMIZATION
void ToBackendConnection::handle_read(const boost::system::error_code& error) {
    if (!error) {
        int i = 0;
        for (; i < 1024; i++) {
            if (m_read_msg[i] == '\n') { break ;}
//            std::cout << m_read_msg[i];
        }
//        std::cout << std::endl;

        //TODO: IMPLEMENT QUEUE LOGIC

        // Firstly deserialize message
        std::stringstream str(std::string(m_read_msg, i));
//        std::cout << str.str() << std::endl;
        boost::archive::text_iarchive iarch(str);
        Message msg;
        iarch >> msg;
//        std::cout << msg.user.devise.sync_folder << std::endl;

        // Secondly push message to the users queue
        QueueManager::queue_manager().push_to_client_queue(std::string(m_read_msg), std::string(msg.user.user_name + msg.user.devise.device_name));
        std::cout << "IN ToBackendConnection::handle_read:: Messages amount for " << std::string(msg.user.user_name + msg.user.devise.device_name) << ": " << QueueManager::queue_manager().get_client_messages_amount(std::string(msg.user.user_name + msg.user.devise.device_name)) << std::endl << std::endl;

        // Then call the send method to server.
        m_server->send_message_if_connected(std::string(msg.user.user_name + msg.user.devise.device_name));

//        m_server->deliver_for_all(m_read_msg);
>>>>>>> development
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
<<<<<<< HEAD
        do_close();
    }
}

void ToBackendConnection::do_write(std::string msg) {
    bool write_in_progress = !m_write_msgs.empty();
    m_write_msgs.push_back(msg);
    if (!write_in_progress) {
=======
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
>>>>>>> development
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
<<<<<<< HEAD
        do_close();
=======
        // DOESN`T WORK RIGHT NOW!
        isConnected = false;
        std::cerr << "ERROR: ToBackendConnection::handle_write" << std::endl;
        std::cerr << "Trying to reconnect!" << std::endl;
        operation = AbstractConnection::last_unsuccess_operation::WRITE;
        m_io_context.reset();
        m_socket.close();
        boost::asio::post(m_io_context,
                          boost::bind(&ToBackendConnection::reconnect, this));
>>>>>>> development
    }
}
