//
// Created by denis on 03.12.2020.
//

#include "clients_connection.h"

clients_connection::clients_connection(
        boost::asio::io_context& io_context,
        const tcp::resolver::results_type& endpoints)
        : AbstractConnection(io_context), io_context_(io_context) {
    boost::asio::async_connect(socket_, endpoints,
                               boost::bind(&clients_connection::handle_connect, this,
                                           boost::asio::placeholders::error));
}

void clients_connection::write(const std::string& msg) {
    boost::asio::post(io_context_,
                      boost::bind(&clients_connection::do_write, this, msg));
}

void clients_connection::close() {
    boost::asio::post(io_context_,
                      boost::bind(&clients_connection::do_close, this));
}

void clients_connection::handle_connect(const boost::system::error_code &error) {
    if (!error) {
        boost::asio::async_read(socket_,
                                boost::asio::buffer(read_msg_),
                                [&] (const boost::system::error_code & err, size_t bytes){ return std::find(read_msg_, read_msg_ + bytes, '\n') < read_msg_ + bytes; },
                                boost::bind(&clients_connection::handle_read, this,
                                            boost::asio::placeholders::error));
    }
}

// TODO: Implement logic of file refresh!
void clients_connection::handle_read(const boost::system::error_code &error) {
    if (!error) {
        for (char i : read_msg_) {
            if (i == '\n') { break ;}
            std::cout << i;
        }
        std::cout << std::endl;
        boost::asio::async_read(socket_,
                                boost::asio::buffer(read_msg_),
                                [&] (const boost::system::error_code & err, size_t bytes){ return std::find(read_msg_, read_msg_ + bytes, '\n') < read_msg_ + bytes; },
                                boost::bind(&clients_connection::handle_read, this,
                                            boost::asio::placeholders::error));
    }
    else { do_close(); }
}

void clients_connection::do_write(std::string msg) {
    bool write_in_progress = !write_msgs_.empty();
    write_msgs_.push_back(msg);
    if (!write_in_progress) {
        boost::asio::async_write(socket_,
                                 boost::asio::buffer(write_msgs_.front().data(), write_msgs_.front().length()),
                                 boost::bind(&clients_connection::handle_write, this,
                                             boost::asio::placeholders::error));
    }
}

void clients_connection::handle_write(const boost::system::error_code &error) {
    if (!error) {
        write_msgs_.pop_front();
        if (!write_msgs_.empty()) {
            boost::asio::async_write(socket_,
                                     boost::asio::buffer(write_msgs_.front().data(),
                                                         write_msgs_.front().length()),
                                     boost::bind(&clients_connection::handle_write, this,
                                                 boost::asio::placeholders::error));
        }
    }
    else { do_close(); }
}
