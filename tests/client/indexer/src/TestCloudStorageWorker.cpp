#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "CloudStorageWorker.h"
#include "utils.h"
#include "TestCloudStorageWorker.h"


TEST(CloudStorageWorker, ReturnedValue) {
    CloudStorageWorker cloud{};

    Message message = create_message();

    EXPECT_EQ(0, cloud.send_to_cloud(message));
}

TEST(CloudStorageWorker, Gmock) {
    MockTestCloudStorageWorker mock;
    Message message = create_message();

    EXPECT_CALL(mock, send_to_cloud(message)).Times(1);
    MockCloudStorageWorker<MockTestCloudStorageWorker> user(&mock);
    user.send(message);
}