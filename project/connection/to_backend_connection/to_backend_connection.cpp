//
// Created by denis on 03.12.2020.
//

#include "to_backend_connection.h"



ToBackendConnection::ToBackendConnection(boost::asio::io_context& io_context,
                                       const tcp::resolver::results_type& endpoints)
        : io_context_(io_context),
          AbstractConnection(io_context) {
    boost::asio::async_connect(socket_, endpoints,
                               boost::bind(&ToBackendConnection::handle_connect, this,
                                           boost::asio::placeholders::error));
}

void ToBackendConnection::set_owner_server(std::shared_ptr<middle_end> serv) {
    server = serv;
}

void ToBackendConnection::write(std::string msg) {
    boost::asio::post(io_context_,
                      boost::bind(&ToBackendConnection::do_write, this, msg));
}

void ToBackendConnection::close() {
    boost::asio::post(io_context_,
                      boost::bind(&ToBackendConnection::do_close, this));
}

void ToBackendConnection::handle_connect(const boost::system::error_code& error) {
    if (!error) {
        boost::asio::async_read(socket_,
                                boost::asio::buffer(read_msg_),
                                [&] (const boost::system::error_code & err, size_t bytes){ return std::find(read_msg_, read_msg_ + bytes, '\n') < read_msg_ + bytes; },
                                boost::bind(&ToBackendConnection::handle_read, this,
                                            boost::asio::placeholders::error));
    } else { std::cerr << "ERROR: to_backend_connection::handle_connect"; }
}

void ToBackendConnection::handle_read(const boost::system::error_code& error) {
    if (!error) {
        for (int i = 0; i < 1024; i++) {
            if (read_msg_[i] == '\n') { break ;}
            std::cout << read_msg_[i];
        }
        std::cout << std::endl;

        //TODO: REMOVE COMMENT
        server->deliver_for_all(read_msg_);
        boost::asio::async_read(socket_,
                                boost::asio::buffer(read_msg_),
                                [&] (const boost::system::error_code & err, size_t bytes){ return std::find(read_msg_, read_msg_ + bytes, '\n') < read_msg_ + bytes; },
                                boost::bind(&ToBackendConnection::handle_read, this,
                                            boost::asio::placeholders::error));
    }
    else {
        do_close();
    }
}

void ToBackendConnection::do_write(std::string msg) {
    bool write_in_progress = !write_msgs_.empty();
    write_msgs_.push_back(msg);
    if (!write_in_progress) {
        boost::asio::async_write(socket_,
                                 boost::asio::buffer(write_msgs_.front().data(), write_msgs_.front().length()),
                                 boost::bind(&ToBackendConnection::handle_write, this,
                                             boost::asio::placeholders::error));
    }
}

void ToBackendConnection::handle_write(const boost::system::error_code& error) {
    if (!error) {
        write_msgs_.pop_front();
        if (!write_msgs_.empty()) {
            boost::asio::async_write(socket_,
                                     boost::asio::buffer(write_msgs_.front().data(),
                                                         write_msgs_.front().length()),
                                     boost::bind(&ToBackendConnection::handle_write, this,
                                                 boost::asio::placeholders::error));
        }
    }
    else { do_close(); }
}