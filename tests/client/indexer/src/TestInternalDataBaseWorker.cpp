#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "TestInternalDataBase.h"
#include "InternalDataBaseWorker.h"
#include "utils.h"

TEST(InternalDataBaseWorker, ReturnedValue) {
    InternalDataBaseWorker internal_data_base;

    Message message = create_message();

    EXPECT_EQ(0, internal_data_base.send_meta_data(message));
}

TEST(InternalDataBaseWorker, Gmock) {
    MockTestInternal mock;
    Message message = create_message();

    EXPECT_CALL(mock, send_meta_data(message)).Times(1);
    MockInternal<MockTestInternal> user(&mock);
    user.send_meta(message);
}