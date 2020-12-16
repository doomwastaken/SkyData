//
// Created by denis on 10.12.2020.
//

#include <fstream>
#include "ClientToStorageConnection.h"

ClientToStorageConnection::ClientToStorageConnection(boost::asio::io_context& io_context, const tcp::resolver::results_type& endpoint)
: AbstractConnection(io_context),
  m_io_context(io_context), endpoint(endpoint) {
    boost::asio::async_connect(m_socket, endpoint,
                               boost::bind(
                                       &ClientToStorageConnection::handle_connect,
                                       this,
                                       boost::asio::placeholders::error));
}

void ClientToStorageConnection::write(const MessageStorage& msg) {
    boost::asio::post(m_io_context,
                      boost::bind(&ClientToStorageConnection::do_write, this, msg, false));
}

void ClientToStorageConnection::close() {
    boost::asio::post(m_io_context,
                      boost::bind(&ClientToStorageConnection::do_close, this));
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(2000ms);
    m_io_context.stop();
}

void ClientToStorageConnection::handle_connect(const boost::system::error_code& error) {
    if (!error) {
        // By default just trying to read
        if (operation == AbstractConnection::last_unsuccess_operation::READ) {
            boost::asio::async_read(m_socket,
                                    boost::asio::buffer(m_read_msg),
                                    [&](const boost::system::error_code &err, size_t bytes) {
                                        return std::find(m_read_msg, m_read_msg + bytes, '\b') < m_read_msg + bytes;
                                    },
                                    boost::bind(&ClientToStorageConnection::handle_read,
                                                this,
                                                boost::asio::placeholders::error));
        }
            // This case will happen only if if will get in error while async_write!
        else if (operation == AbstractConnection::last_unsuccess_operation::WRITE) {
            // Just trying to write the same message before the failure in async_write
            do_write(MessageStorage {}, true);
        }
    } else {
        std::cerr << "ERROR: ClientToStorageConnection::handle_connect" << std::endl;
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(1000ms);
        // Trying to reconnect!
        boost::asio::async_connect(m_socket, endpoint,
                                   boost::bind(
                                           &ClientToStorageConnection::handle_connect,
                                           this,
                                           boost::asio::placeholders::error));
    }
}

void ClientToStorageConnection::handle_read(const boost::system::error_code& error) {
    if (!error) {
        std::string raw_string;
        int i = 0;
        while (m_read_msg[i] != '\b') {
            raw_string += m_read_msg[i];
            i++;
        }
        std::cout << std::endl;
        std::stringstream str(raw_string);
        boost::archive::text_iarchive iarch(str);
        MessageStorage msg;
        iarch >> msg;

        std::fstream file(msg.file_name + msg.file_extension, std::ios::binary | std::ios::out);
        std::cout << "Size: " << msg.RAW_BYTES.size() << std::endl;
//        std::cout << msg.RAW_BYTES << std::endl;
//        file << msg.RAW_BYTES;
        file.write((char*)&msg.RAW_BYTES[0], msg.RAW_BYTES.size());
        file.close();



        boost::asio::async_read(m_socket,
                                boost::asio::buffer(m_read_msg),
                                [&] (const boost::system::error_code & err, size_t bytes)
                                { return std::find(m_read_msg, m_read_msg + bytes, '\b') < m_read_msg + bytes; },
                                boost::bind(
                                        &ClientToStorageConnection::handle_read,
                                        this,
                                        boost::asio::placeholders::error));
    }
    else { do_close(); }
}

void ClientToStorageConnection::do_write(MessageStorage msg, bool continue_writing) {
    bool write_in_progress = !m_write_msgs.empty();
    // Serialize our Message struct to string
    if (!continue_writing) {
        if (msg.status == PUSH_FILE) {
            std::fstream file(msg.file_name + msg.file_extension, std::ios::binary | std::ios::in);
            char c = file.get();
            while(file.good()) {
                msg.RAW_BYTES.push_back(c);
                c = file.get();
            }
        }
        std::stringstream str;
        boost::archive::text_oarchive oarch(str);
        oarch << msg;
        // The "\b" is a SEPARATOR FOR MESSAGES!
        m_write_msgs.push_back(str.str() + '\b');
    }
    if (!write_in_progress) {
        boost::asio::async_write(m_socket,
                                 boost::asio::buffer(m_write_msgs.front().data(), m_write_msgs.front().length()),
                                 boost::bind(&ClientToStorageConnection::handle_write, this,
                                             boost::asio::placeholders::error));
    }
}

void ClientToStorageConnection::handle_write(const boost::system::error_code& error) {
    if (!error) {
    m_write_msgs.pop_front();
    if (!m_write_msgs.empty()) {
    boost::asio::async_write(m_socket,
            boost::asio::buffer(m_write_msgs.front().data(),
                                m_write_msgs.front().length()),
            boost::bind(&ClientToStorageConnection::handle_write, this,
                        boost::asio::placeholders::error));
    }
    }
    else {
    std::cerr << "ERROR: ClientToStorageConnection::handle_write" << std::endl;
    std::cerr << "Trying to reconnect!" << std::endl;
    operation = AbstractConnection::last_unsuccess_operation::WRITE;
    boost::asio::async_connect(m_socket, endpoint,
            boost::bind(
            &ClientToStorageConnection::handle_connect,
            this,
            boost::asio::placeholders::error));
    }
}