#include <PopCommand.h>


int PopCommand::command() {
    if (client_socked.pop() < 0) {
        return EXIT_FAILURE;
    }
    messages.push(client_socked.deserialize());
    return EXIT_SUCCESS;
}

std::shared_ptr<Message> PopCommand::get_message() {
    if (messages.empty())
        return nullptr;
    std::shared_ptr<Message> &mes = messages.front();
    messages.pop();
    return mes;
}

bool PopCommand::is_empty() {
    return messages.empty();
}


