#include "gtest/gtest.h"
#include "InternalDataBaseWorker.h"
#include "utils.h"

TEST(Internal_Data_Base_Worker, ReturnedValue) {
    InternalDataBaseWorker internal_data_base;

    Message message = create_message();

    EXPECT_EQ(0, internal_data_base.send_meta_data(message));
}