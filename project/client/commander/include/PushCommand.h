#ifndef PROJECT_PUSHCOMMAND_H
#define PROJECT_PUSHCOMMAND_H

#include <vector>
#include "ClientCommand.h"

class PushCommand : public ClientCommand {
public:
    void command() override;

private:
    std::vector<Message> messages;
};

#endif //PROJECT_PUSHCOMMAND_H
