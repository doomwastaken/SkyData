#include "MessageUpdater.h"
#include "ClientSender.h"
#include "ClientToStorageConnection.h"


void MessageUpdater::to_client_send(ClientsConnection &cl_con) {//, ClientToStorageConnection &storage_conn) {
    mtx.lock();
    if (!processed_messages.empty()) {
        while (!processed_messages.empty()) {
            std::cout << "NOT EMPTY!" << std::endl;
            if (!processed_messages.front().second) {
                sender.send(processed_messages.front().first, cl_con, ClientSender::ONLY_SQL);
                // TODO: Download from server
            }
            else {
                sender.send(processed_messages.front().first, cl_con, ClientSender::BOTH);
                // ZAGLUSHKA
//                storage_devise_t device2{processed_messages.front().first->user.devise.device_name, processed_messages.front().first->user.devise.sync_folder};
//                storage_user_t user2{processed_messages.front().first->user.user_name, "email@ml.com", device2, 10};
//
//                MessageStorage msg2{10, storage_status_t::PUSH_FILE, false,
//                                    2, processed_messages.front().first->file_name, processed_messages.front().first->file_extension,
//                                    100, "/home/denis/Desktop/" + processed_messages.front().first->user.user_name, user2};
//                storage_conn.write(msg2);
                // TODO: Load on server!!
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

MessageUpdater::MessageUpdater() {

}
