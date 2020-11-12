#include "gtest/gtest.h"
#include "Cloud_Storage_Worker.h"
#include "utils.h"

TEST(Cloud_Storage_Worker, ReturnedValue) {
    Cloud_Storage_Worker cloud;

    Message message = create_message();

    EXPECT_EQ(0, cloud.send_to_cloud(message));
}
