//
// Created by denis on 03.12.2020.
//

#include "server_connection.h"
#include "../../server/abstract_server.h"

server_connection::server_connection(boost::asio::io_context& io_context, std::shared_ptr<abstract_server> srvr)
: AbstractConnection(io_context), server_ptr(srvr) { ; }

boost::asio::ip::tcp::socket& server_connection::socket() { return socket_; }

void server_connection::start() {
    boost::asio::async_read(socket_,
                            boost::asio::buffer(read_msg_),
                            [&] (const boost::system::error_code & err, size_t bytes){ return std::find(read_msg_, read_msg_ + bytes, '\n') < read_msg_ + bytes; },
                            boost::bind(
                                    &server_connection::handle_read, shared_from_this(),
                                    boost::asio::placeholders::error));
}

void server_connection::handle_read(const boost::system::error_code& error) {
    if (!error)
    {
        for (const char& i : read_msg_) {
            if (i == '\n') { break; }
            std::cout << i;
        }
        std::cout << std::endl;

        server_ptr->on_readed_message(read_msg_);

        boost::asio::async_read(socket_,
                                boost::asio::buffer(read_msg_),
                                [&] (const boost::system::error_code & err, size_t bytes){ return std::find(read_msg_, read_msg_ + bytes, '\n') < read_msg_ + bytes; },
                                boost::bind(
                                        &server_connection::handle_read, shared_from_this(),
                                        boost::asio::placeholders::error));
    }
    else
    {
        std::cerr << "Fault";
    }
}

void server_connection::deliver(char* msg) {
    bool write_in_progress = !write_msgs_.empty();
    write_msgs_.emplace_back(msg);
    if (!write_in_progress)
    {
        boost::asio::async_write(socket_,
                                 boost::asio::buffer(write_msgs_.front().data(),
                                                     write_msgs_.front().length()),
                                 boost::bind(&server_connection::handle_write, shared_from_this(),
                                             boost::asio::placeholders::error));
    }
}

void server_connection::handle_write(const boost::system::error_code& error) {
    if (!error) {
        write_msgs_.pop_front();
        if (!write_msgs_.empty()) {
            boost::asio::async_write(socket_,
                                     boost::asio::buffer(write_msgs_.front().data(),
                                                         write_msgs_.front().length()),
                                     boost::bind(&server_connection::handle_write, shared_from_this(),
                                                 boost::asio::placeholders::error));
        }
    }
    else { std::cerr << "Error handle_write! " << error.message(); }
}