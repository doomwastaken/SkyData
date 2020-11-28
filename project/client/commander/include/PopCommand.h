#ifndef PROJECT_POPCOMMAND_H
#define PROJECT_POPCOMMAND_H

#include "queue"
#include "ClientCommand.h"

class PopCommand : public ClientCommand {
public:
    void command() override;
    std::shared_ptr<Message> get_message();


private:
    std::queue<std::shared_ptr<Message>> messages;
};

#endif //PROJECT_POPCOMMAND_H
