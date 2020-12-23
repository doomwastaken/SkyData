#include <fstream>
#include "ServerConnection.h"
#include "AbstractServer.h"
#include "Message.h"

// FIXME: remove this
void print_mes_serv(Message &message) {
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
    std::cout << "status: " << message.status << std::endl;
}

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

                            { return (std::find(m_read_msg, m_read_msg + bytes, '\b') < m_read_msg + bytes ||
                                      std::find(m_read_msg, m_read_msg + bytes, EOF) < m_read_msg + bytes); },
                            boost::bind(
                                    &ServerConnection::handle_read,
                                    shared_from_this(),
                                    boost::asio::placeholders::error));
}

void ServerConnection::handle_read(const boost::system::error_code& error) {
    if (!error) {
        std::cout << "HANDLE_READ" << std::endl;
        int i = 0;
        for (; m_read_msg[i] != '\b'; i++) {
            std::cout << m_read_msg[i]; }
        std::cout << std::endl;


        std::string str_mes = m_read_msg;
        std::stringstream str(str_mes);
        boost::archive::text_iarchive iarch(str);
        Message msg;
        iarch >> msg;

        std::cout << "Server: " << std::endl;

        print_mes_serv(msg);

        if (this->id.empty()) {
            m_server_ptr->remove_connection(msg.user.user_name + msg.user.devise.device_name);
            this->id = msg.user.user_name + msg.user.devise.device_name;
            QueueManager::queue_manager().create_queue_if_not_exists(this->id);
            // Do we have messages for user in queue?
            while (QueueManager::queue_manager().is_user_queue_exists(this->id) &&
                  !QueueManager::queue_manager().is_user_queue_empty(this->id)) {
                m_server_ptr->send_message_if_connected(this->id);
            }
        }

        m_server_ptr->on_readed_message(m_read_msg);

        boost::asio::async_read(m_socket,
                                boost::asio::buffer(m_read_msg),
                                [&] (const boost::system::error_code & err, size_t bytes)
                                { return (std::find(m_read_msg, m_read_msg + bytes, '\b') < m_read_msg + bytes); },// ||
//                                           std::find(m_read_msg, m_read_msg + bytes, EOF) < m_read_msg + bytes); },
                                boost::bind(
                                            &ServerConnection::handle_read,
                                            shared_from_this(),
                                            boost::asio::placeholders::error));
    } else {
        std::cerr << "Fault";
    }
}


void ServerConnection::deliver(std::string msg) {
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
        m_server_ptr->remove_connection(this->id, m_write_msgs.front());
        std::cerr << "Error handle_write! " << error.message();
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
    }
}

void ServerConnection::find_file_and_send(Message msg) {;
    std::fstream file(msg.user.devise.sync_folder + "/" + msg.file_name + msg.file_extension, std::ios::binary | std::ios::in);
//    while (file.good()) {
//        std::cout << file.get() << " ";
//    }
//    std::cout << std::endl;
    Message msg_to_send;

    msg_to_send.version = msg.version;
    msg_to_send.status = msg.status;
    msg_to_send.times_modified = msg.times_modified;
    msg_to_send.file_name = msg.file_name;  // "file"
    msg_to_send.file_extension = msg.file_extension;  // ".png"
    msg_to_send.file_size = msg.file_size;
    msg_to_send.file_path = msg.file_path;  // "./dir/dir1/"
    msg_to_send.user = msg.user;


    file.close();

    file.open(msg.user.devise.sync_folder + "/" + msg.file_name + msg.file_extension, std::ios::binary | std::ios::in);
//
    char c = file.get();
    while (file.good()) {
        msg_to_send.RAW_BYTES.push_back(c);
        c = file.get();
    }
    file.close();
    std::cout << "SIZE: " << msg_to_send.RAW_BYTES.size() << std::endl;
//    std::cout <<  "RAW BYTES: " << msg_to_send.RAW_BYTES << std::endl;

    std::stringstream str;
    boost::archive::text_oarchive oarch(str);
    oarch << msg_to_send;
    // The "\b" is a SEPARATOR FOR MESSAGES!


//    std::fstream file_check(msg.file_name + msg.file_extension, std::ios::binary | std::ios::out);
//    file_check.write((char*)&msg_to_send.RAW_BYTES[0], msg_to_send.RAW_BYTES.size());
//    file_check.close();

    std::cout << str.str() << std::endl;
    boost::asio::write(m_socket,
                             boost::asio::buffer(str.str(),
                                                 str.str().size()));

//    std::size_t size = file.rdbuf()->pubseekoff(0, file.end, file.in);
//    boost::asio::write(m_socket,
//                       boost::asio::buffer(file.rdbuf(),
//                                           size),
//                       [&] (const boost::system::error_code & err, size_t bytes) { return !file.good(); });

    std::string backB = "\b";
    boost::asio::write(m_socket,
                       boost::asio::buffer(backB,
                                           backB.size()));

}

void ServerConnection::change_file_on_server(Message msg) {
//    std::fstream file(msg.user.devise.sync_folder + "/" + msg.file_name + msg.file_extension, std::ios::binary | std::ios::in);
////
//
//    for (const auto& chr : msg.RAW_BYTES) {
//        file << chr;
//    }
//    file.close();
}
