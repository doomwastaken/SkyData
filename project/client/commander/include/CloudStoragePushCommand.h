#ifndef PROJECT_CLOUDSTORAGEPUSHCOMMAND_H
#define PROJECT_CLOUDSTORAGEPUSHCOMMAND_H

#include <queue>
#include "ClientCommand.h"
#include "Message.h"

class CloudStoragePushCommand : public ClientCommand {
public:
    int command() override;

    void add_message(const std::shared_ptr<Message>& mes);
    bool is_empty();

private:
    std::queue<std::shared_ptr<Message>> message;

};

#endif //PROJECT_CLOUDSTORAGEPUSHCOMMAND_H
