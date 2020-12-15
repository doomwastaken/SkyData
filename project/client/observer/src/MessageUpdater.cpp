#include "MessageUpdater.h"


void MessageUpdater::to_client_send(ClientsConnection &cl_con) {
    mtx.lock();
    if (!processed_messages.empty()) {
        while (!processed_messages.empty()) {
            sender.send(processed_messages.front(), cl_con);
            processed_messages.pop();
        }
    }
    mtx.unlock();

}

void MessageUpdater::push(const std::shared_ptr<Message> &message) {
    mtx_stat.lock();
    processed_messages.push(message);
    mtx_stat.unlock();
}

MessageUpdater::MessageUpdater() {

}
