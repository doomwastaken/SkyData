#ifndef PROJECT_POPCOMMAND_H
#define PROJECT_POPCOMMAND_H

#include <vector>
#include "ClientCommand.h"

class PopCommand : public ClientCommand {
public:
    void command() override;

private:
    std::vector<Message> messages;
};

#endif //PROJECT_POPCOMMAND_H
