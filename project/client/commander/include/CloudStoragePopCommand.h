#ifndef PROJECT_CLOUDSTORAGEAPI_H
#define PROJECT_CLOUDSTORAGEAPI_H

#include <queue>
#include "ClientCommand.h"
#include "Message.h"


class CloudStoragePopCommand : public ClientCommand {
public:
    int command() override;

    void add_message(const std::shared_ptr<Message>& mes);
    bool is_empty();

private:
    std::queue<std::shared_ptr<Message>> message;

};

#endif //PROJECT_CLOUDSTORAGEAPI_H
