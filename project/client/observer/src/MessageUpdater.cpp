#include "MessageUpdater.h"


void MessageUpdater::to_client_send(ClientsConnection &cl_con) {
    mtx.lock();
    if (!processed_messages.empty()) {
        while (!processed_messages.empty()) {
            sender.send(processed_messages.front().first, cl_con);
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
