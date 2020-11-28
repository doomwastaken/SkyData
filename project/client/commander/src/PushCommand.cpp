#include "PushCommand.h"


void PushCommand::command() {

    client_socked.serialize(*messages.front());
    if (client_socked.send() < 0)
        return;
    return;
}

void PushCommand::push_message(const std::shared_ptr<Message>& message) {
    messages.push(message);
}

std::shared_ptr<Message> PushCommand::proverka(const std::shared_ptr<Message>& message) {

//    client_socked.serialize(*messages.front()); // Сигсегв
    if (client_socked.send() < 0)
        return nullptr;
    return messages.front();
}
