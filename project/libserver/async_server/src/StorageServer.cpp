//
// Created by denis on 09.12.2020.
//

#include <fstream>
#include "StorageServer.h"
#include "MessageStorage.h"

void StorageServer::start_accept() {
    boost::shared_ptr<ServerConnection> new_connect(new ServerConnection(m_io_context,
                                                                         std::shared_ptr<AbstractServer>(this)));
    m_acceptor.async_accept(new_connect->socket(),
                            boost::bind(
                                    &StorageServer::handle_accept,
                                    this,
                                    new_connect,
                                    boost::asio::placeholders::error));
}


void StorageServer::deliver_for_all(std::string msg) {
    std::for_each(m_connections.begin(), m_connections.end(),
                  boost::bind(&ServerConnection::deliver, _1, boost::ref(msg)));
}

void StorageServer::on_readed_message(char* msg_str) {
    std::stringstream str(msg_str);
    boost::archive::text_iarchive iarch(str);
    MessageStorage msg;
    iarch >> msg;
    if (msg.status == storage_status_t::DOWNLOAD_FILE) {
        for (auto &connection: m_connections) {
            //        std::cout << "Messages amount for " << connection->id << ": " << QueueManager::queue_manager().get_client_messages_amount(connection->id) << std::endl << std::endl;
            if (connection->id == msg.user.user_name + msg.user.devise.device_name) {
                boost::bind(&ServerConnection::find_file_and_send, _1, msg)(connection);
                break;
            }
        }
    }
    else if (msg.status == storage_status_t::PUSH_FILE) {
        std::fstream file(msg.user.devise.sync_folder + "/" + msg.file_name + msg.file_extension, std::ios::binary | std::ios::in | std::ios::out);
        file << msg.RAW_BYTES;
        file.close();
    }
}

StorageServer::StorageServer(boost::asio::io_context &io_context, const tcp::endpoint &endpoint) : AbstractServer(
        io_context, endpoint) { ; }
