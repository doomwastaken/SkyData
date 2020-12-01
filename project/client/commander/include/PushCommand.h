#ifndef PROJECT_PUSHCOMMAND_H
#define PROJECT_PUSHCOMMAND_H

#include <queue>
#include "ClientCommand.h"


class PushCommand : public ClientCommand {
public:
    int command() override;
//    std::shared_ptr<Message> proverka(const std::shared_ptr<Message>& message);
    void push_message(const std::shared_ptr<Message>& message);
    bool is_empty();

private:
    std::queue<std::shared_ptr<Message>> messages;

    // std::vector<Message> messages;
};

#endif //PROJECT_PUSHCOMMAND_H
