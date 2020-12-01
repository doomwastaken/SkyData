#ifndef PROJECT_POPCOMMAND_H
#define PROJECT_POPCOMMAND_H

#include "queue"
#include "ClientCommand.h"

class PopCommand : public ClientCommand {
public:
    int command() override;

    std::shared_ptr<Message> get_message();
    bool is_empty();

private:
    std::queue<std::shared_ptr<Message>> messages;
};

#endif //PROJECT_POPCOMMAND_H
