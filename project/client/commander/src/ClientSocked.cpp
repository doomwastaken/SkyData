
#include "ClientSocked.h"

ClientSocked::ClientSocked(std::string &host, int port) :
        m_socket(m_io_service),
        m_host(host),
        m_port(port),
        m_timeout(0) {  // ToDo: Литерал заменить на секунды boostDataTime.
}

ClientSocked::~ClientSocked() {
    m_socket.close();
}

int ClientSocked::connection() {
    as::ip::tcp::endpoint endpoint(as::ip::address::from_string(m_host), m_port);


//    try ToDo: Раскомментить
//    {
    m_socket.connect(endpoint);
//    }
//    catch (const boost::system::system_error& e) {
//         Ошибка
//    }
    return 0;
}

int ClientSocked::send() {
    int read_bytes = 0;
//    try { ToDo: Раскомментить
        read_bytes = as::write(m_socket, as::buffer(buf_send));
//    }
//    catch (const boost::system::system_error& error) {
//        Ошибка
//    }

    return read_bytes;
}

int ClientSocked::pop() {
    as::streambuf buf;
    int read_size = 0;
//    try { ToDo: Раскомментить
        read_size = as::read_until(m_socket, buf, "\0");
//    }
//    catch(std::exception& error {
//        Ошибка
//    }
    buf_pop = as::buffer_cast<const char*>(buf.data());
    return read_size;
}

void ClientSocked::close() const {

}

void ClientSocked::serialize(const std::shared_ptr<Message>& message) {
    std::stringstream stream;
    boost::archive::text_oarchive oarchive(stream);
    oarchive << *message;
    buf_send = stream.str();
}

std::shared_ptr<Message> ClientSocked::deserialize() const {
    auto new_message = std::make_shared<Message>();
    std::stringstream stream;
    stream << buf_pop;
        boost::archive::text_iarchive iarchive(stream);
        iarchive >> *new_message;

    return new_message;
}

ClientSocked::ClientSocked() :
        m_socket(m_io_service),
        m_host("127.0.0.1"),
        m_port(7777),
        m_timeout(0)
        {}
