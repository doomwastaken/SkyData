#include "MessageUpdater.h"




void MessageUpdater::to_client_send() {
    sender.send(processed_messages.front());
    processed_messages.pop();
}

void MessageUpdater::push(const std::shared_ptr<Message>& message) {
    processed_messages.push(message);
}

MessageUpdater::MessageUpdater()  {

}
