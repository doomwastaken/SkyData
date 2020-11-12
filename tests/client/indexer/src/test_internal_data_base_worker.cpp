#include "gtest/gtest.h"
#include "Internal_Data_Base_Worker.h"
#include "utils.h"

TEST(Internal_Data_Base_Worker, ReturnedValue) {
    Internal_Data_Base_Worker internal_data_base;

    Message message = create_message();

    EXPECT_EQ(0, internal_data_base.send_to_data_base(message));
}