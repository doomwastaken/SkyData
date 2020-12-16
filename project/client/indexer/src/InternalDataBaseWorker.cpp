#include "Message.h"
#include "InternalDataBaseWorker.h"
#include "SQLite.h"

int InternalDataBaseWorker::send_meta_data(std::shared_ptr<Message> &message) {
    data_base = std::make_shared<SQLite>();
    if (!data_base->update(*message)) {
        // TODO: Добавить логирование
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

//InternalDataBaseWorker::InternalDataBaseWorker() = default;