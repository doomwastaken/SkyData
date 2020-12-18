#include "MessageUpdater.h"
#include "ClientSender.h"
#include "ClientToStorageConnection.h"


void MessageUpdater::to_client_send(ClientsConnection &cl_con, ClientToStorageConnection &storage_conn) {
    mtx.lock();
    if (!processed_messages.empty()) {
        while (!processed_messages.empty()) {
            std::cout << processed_messages.front().first->file_name << " QUEUE\n";
            std::cout << file_double_mes << " FILE_DOUBLE\n";

            if (processed_messages.front().first->file_name == file_double_mes) {
                file_double_mes = "";
                processed_messages.pop();
                std:: cout << "UUUUUUUUUUUUUUUUUUUUUUUUU\n";
                continue;
            }

            if (!processed_messages.front().second) {
                sender.send(processed_messages.front().first, cl_con, storage_conn, ClientSender::ONLY_SQL, file_double_mes);
                // TODO: Download from server
            }
            else {
                sender.send(processed_messages.front().first, cl_con, storage_conn,  ClientSender::BOTH, file_double_mes);
            }

            processed_messages.pop();
        }
    }
    mtx.unlock();

}

void MessageUpdater::push(const std::shared_ptr<Message> &message, bool is_from_queue) {
    mtx_stat.lock();
    //std::pair<std::shared_ptr<Message>, bool> f;
    //processed_messages.push(message, boooool);
    processed_messages.push(std::pair<std::shared_ptr<Message>, bool>(message,is_from_queue));
    mtx_stat.unlock();
}

MessageUpdater::MessageUpdater() : file_double_mes("") {

}
