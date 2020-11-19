#include "gtest/gtest.h"
#include "CloudStorageWorker.h"
#include "utils.h"

TEST(CloudStorageWorker, ReturnedValue) {
    CloudStorageWorker cloud{};

    Message message = create_message();

    EXPECT_EQ(0, cloud.send_to_cloud(message));
}
