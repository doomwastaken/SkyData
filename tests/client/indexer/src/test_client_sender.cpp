#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "ClientSender.h"
#include "CloudStorageWorker.h"
#include "InternalDataBaseWorker.h"
#include "utils.h"

using ::testing::AtLeast;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::SetArgReferee;

TEST(ClientSender, ReturnedValue) {
ClientSender client_sender;

Message message = create_message();

EXPECT_EQ(0, client_sender.send(message));
}

TEST(ClientSender, CallCloudWorker) {
    ClientSender client_sender;
    CloudStorageWorker worker{};
    Message message = create_message();

    EXPECT_EQ(0, client_sender.send(message));
    EXPECT_CALL(client_sender, worker.send_to_cloud(message)).Times(1);
}

TEST(ClientSender, CallInternalWorker) {
    ClientSender client_sender;
    InternalDataBaseWorker worker{};
    Message message = create_message();

    EXPECT_EQ(0, client_sender.send(message));
    EXPECT_CALL(client_sender, worker.send_meta_data(message)).Times(1);
}