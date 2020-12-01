#include <boost/filesystem.hpp>
#include <fstream>
#include "CloudStoragePopCommand.h"

int CloudStoragePopCommand::command() {
    const std::shared_ptr<Message>& mes = message.front();
    message.pop();
    if (client_socked.pop() < 0) {
        return EXIT_FAILURE;
    }
    boost::filesystem::create_directories(mes->file_path);
    std::ofstream of(mes->file_path + mes->file_name + mes->file_extension);

    of << client_socked.buf_pop;
    if (!of.is_open()) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

bool CloudStoragePopCommand::is_empty() {
    return message.empty();
}

void CloudStoragePopCommand::add_message(const std::shared_ptr<Message> &mes) {
    message.push(mes);
}


