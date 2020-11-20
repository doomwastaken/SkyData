#ifndef PROJECT_CONNECTION_H
#define PROJECT_CONNECTION_H

#include <string>

#include "EventLoop.h"
#include "Message.h"

class Connection {
public:
    explicit Connection(int sd, EventLoop &event_loop) : m_sd(sd), event_loop(event_loop) {}

    void read();

    void write(Message message);

private:
    void read_handler();

    void write_handler();

    std::string m_read_buf;

    std::string m_write_buf;

    int m_sd;

    EventLoop &event_loop;

    size_t user_id{};
};


#endif //PROJECT_CONNECTION_H
