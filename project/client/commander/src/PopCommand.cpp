#include <PopCommand.h>


void PopCommand::command() {
    if (client_socked.pop() < 0) {
        return;
    }
    messages.push(client_socked.deserialize());
    return;
}

std::shared_ptr<Message> PopCommand::get_message() {
    if (messages.empty())
        return nullptr;
    std::shared_ptr<Message> &mes = messages.front();
    messages.pop();
    return mes;
}


