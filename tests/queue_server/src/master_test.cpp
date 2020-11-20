#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../include/master_mock.h"

using ::testing::AtLeast;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::SetArgReferee;

TEST(MASTER, RUN_SERVER) {
    Mock_Master master(777);
    EXPECT_CALL(master, run_server()).Times(AtLeast(1));
    User<Mock_Master> user(&master);
    user.run_server();
}

TEST(MASTER, CREATE_CONNECTION) {
    Mock_Master master(777);
    Socket socket(WANT_READ);
    EventLoop loop = EventLoop::eventLoop();
    EXPECT_CALL(master, create_connection(socket, loop)).Times(AtLeast(1));
    User<Mock_Master> user(&master);
    user.create_connection(socket, loop);
}