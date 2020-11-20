#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "QueueManager.h"

using ::testing::AtLeast;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::SetArgReferee;

TEST(MANAGER, SET_TYPES) {
    QueueManager manager = QueueManager::queue_manager();
    EXPECT_NO_THROW(manager.set_sync_queue_type(STD_QUEUE));
    EXPECT_NO_THROW(manager.set_client_queue_type(ON_DISK_QUEUE));
}

TEST(MANAGER, PUSHPOPSTABLE) {
    QueueManager manager = QueueManager::queue_manager();
    Message push;
    Message pop;
    ASSERT_NO_THROW(manager.push_to_syncserv_queue(push));
    ASSERT_NO_THROW(pop = manager.pop_from_syncserv_queue());
//    EXPECT_EQ(push, pop);
}

TEST(MANAGER, SYNCSERVISEMPTY) {
    QueueManager manager = QueueManager::queue_manager();
    manager.push_to_syncserv_queue(Message());
    EXPECT_FALSE(manager.is_syncserv_queue_empty());
    manager.pop_from_syncserv_queue();
    EXPECT_TRUE(manager.is_syncserv_queue_empty());
}

TEST(MANAGER, USERISEMPTY) {
    QueueManager manager = QueueManager::queue_manager();
    manager.push_to_client_queue(Message(), 0);
    EXPECT_FALSE(manager.is_user_queue_empty(0));
    manager.pop_from_client_queue(0);
    EXPECT_TRUE(manager.is_user_queue_empty(0));
}