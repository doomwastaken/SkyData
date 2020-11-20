#ifndef PROJECT_QUEUE_MOCK_H
#define PROJECT_QUEUE_MOCK_H

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "QueueAPI.h"
#include "Queue.h"

#include <vector>
#include <string>

class Mock_Queue : public Queue {
public:
    MOCK_METHOD(void, push_to_queue, (Message message), ());
    MOCK_METHOD(Message, pop_from_queue, (), ());
};

#endif //PROJECT_QUEUE_MOCK_H
