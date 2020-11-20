#ifndef PROJECT_MASTER_H
#define PROJECT_MASTER_H

#include "Socket.h"

#include "EventLoop.h"

class Master {
public:
    explicit Master(int listener, int timeout = 100) :
        timeout(timeout),
        listener(listener)
        {};

    void run_server();

private:
    void listen();

    void create_connection(Socket socket,  EventLoop &event_loop);

    int timeout;
    int listener;
};


#endif //PROJECT_MASTER_H
