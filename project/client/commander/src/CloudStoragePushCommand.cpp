#include <boost/filesystem.hpp>
#include <fstream>
#include "CloudStoragePushCommand.h"

int CloudStoragePushCommand::command() {
    const std::shared_ptr<Message>& mes = message.front();
    message.pop();
    std::ifstream of(mes->file_path + mes->file_name + mes->file_extension);

    char buf[512];
    while (of.read(buf, sizeof(buf)).gcount() > 0) {
        client_socked.buf_send.append(buf, of.gcount());
    }

    if (client_socked.send() < 0)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

bool CloudStoragePushCommand::is_empty() {
    return message.empty();
}

void CloudStoragePushCommand::add_message(const std::shared_ptr<Message> &mes) {
    message.push(mes);
}
