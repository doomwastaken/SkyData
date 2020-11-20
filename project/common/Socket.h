#ifndef PROJECT_SOCKET_H
#define PROJECT_SOCKET_H
#include <unistd.h>
#include <memory>
#include <string>

#include "Message.h"

typedef enum {
    WANT_READ,
    WANT_WRITE
}state_t;

class Socket {
public:
    explicit Socket(state_t state) : m_socket(-1), m_state(state) {}

    explicit Socket(int sd, state_t state) : m_socket(sd), m_state(state) {}

    ~Socket();

    void connect(const std::string& host, int port);

    void send(Message);

    Message recv();

    void setNonBlocked();

    std::shared_ptr<Socket> accept();

    void close();

    int get_socket_descr();

    state_t &get_state();

private:
    int m_socket;
    state_t m_state;
};


#endif //PROJECT_SOCKET_H
