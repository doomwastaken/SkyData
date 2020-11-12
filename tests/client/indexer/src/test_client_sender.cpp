#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Client_Sender.h"
#include "Cloud_Storage_Worker.h"
#include "Internal_Data_Base_Worker.h"
#include "utils.h"

using ::testing::AtLeast;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::SetArgReferee;

TEST(Client_Sender, ReturnedValue) {
Client_Sender client_sender;

Message message = create_message();

EXPECT_EQ(0, client_sender.send(message));
}

TEST(Client_Sender, CallCloudWorker) {
    Client_Sender client_sender;
    Cloud_Storage_Worker worker{};
    Message message = create_message();

    EXPECT_EQ(0, client_sender.send(message));
    EXPECT_CALL(client_sender, worker.send_to_cloud(message)).Times(1);
}

TEST(Client_Sender, CallInternalWorker) {
    Client_Sender client_sender;
    Internal_Data_Base_Worker worker{};
    Message message = create_message();

    EXPECT_EQ(0, client_sender.send(message));
    EXPECT_CALL(client_sender, worker.send_to_data_base(message)).Times(1);
}