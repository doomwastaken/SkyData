//
// Created by Олег Реуцкий on 20.11.2020.
//

#include "Socket.h"

void Socket::connect(const std::string &host, int port) {

}

void Socket::send(Message) {

}

Message Socket::recv() {
    return Message();
}

void Socket::setNonBlocked() {

}

std::shared_ptr<Socket> Socket::accept() {
    return std::shared_ptr<Socket>();
}

void Socket::close() {
    ::close(m_socket);
}

int Socket::get_socket_descr() {
    return m_socket;
}

state_t &Socket::get_state() {
    return m_state;
}

Socket::~Socket() {
    if (m_socket > 0) {
        ::close(m_socket);
    }
}

