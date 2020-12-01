#include "PushCommand.h"


int PushCommand::command() {

    client_socked.serialize(messages.front());
    if (client_socked.send() < 0)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

void PushCommand::push_message(const std::shared_ptr<Message>& message) {
    messages.push(message);
}

bool PushCommand::is_empty() {
    return messages.empty();
}

//std::shared_ptr<Message> PushCommand::proverka(const std::shared_ptr<Message>& message) {
//    messages.push(message);
//
//    client_socked.serialize(messages.front()); // Сигсегв
//    if (client_socked.send() < 0)
//        return nullptr;
//    return messages.front();
//}
