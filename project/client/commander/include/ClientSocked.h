#ifndef PROJECT_CLIENTSOCKED_H
#define PROJECT_CLIENTSOCKED_H

#include <string>
#include <Message.h>

class ClientSocked {
public:
    ClientSocked();
    void connect(const std::string& host,
                 int port,
                 int timeout);
    void send(Message message);
    void close();
private:
    const std::string host;
    int port;
    int timeout;

};

#endif //PROJECT_CLIENTSOCKED_H
