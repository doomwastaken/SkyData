#ifndef PROJECT_MASTER_H
#define PROJECT_MASTER_H

#include "Socket.h"

#include "EventLoop.h"

class Master {
public:
    explicit Master(Socket server_socket, int timeout, int listener) :
        server_socket(server_socket),
        timeout(timeout),
        listener(listener)
        {};

    void run_server();

private:
    void listen();

    void create_connection(Socket socket,  EventLoop &event_loop);

    Socket server_socket;

    int timeout;

    int listener;
};


#endif //PROJECT_MASTER_H
