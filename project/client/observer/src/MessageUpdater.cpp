#include "MessageUpdater.h"




void MessageUpdater::to_client_send() {
    mtx.lock();
    if (!processed_messages.empty()) {
        sender.send(processed_messages.front());
        processed_messages.pop();
    }
    mtx.unlock();

}

void MessageUpdater::push(const std::shared_ptr<Message>& message) {
    mtx_stat.lock();
    processed_messages.push(message);
    mtx_stat.unlock();
}

MessageUpdater::MessageUpdater()  {

}
