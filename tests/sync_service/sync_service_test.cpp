#include <fstream>
#include <iostream>
#include <sstream>
#include <random>
#include <queue>
#include <pqxx/pqxx>

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "PostgressDB.h"
#include "DataBase.h"

using ::testing::_;
using ::testing::AtLeast;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::SetArgReferee;

class MockDatabase: public PostgressDB {
public:
    MOCK_METHOD(std::string, select, (const std::string str));
};

TEST(test_worker, test1) {
    MockDatabase db;
    Message message;
    message.status = LOGIN;
    message.user.user_name = "Oleg";
    db.update(message);
    std::string quote = "'";

    const std::string first_arg = "SELECT * from USERS_DEVISES "
                    "WHERE device_name = " + quote + message.user.devise.device_name + quote;

    EXPECT_CALL(db, select(first_arg))
            .Times(1), Return("result");

    std::vector<Message> messages = db.update(message);

    ASSERT_EQ(messages[0].user.user_name, "Oleg");
    ASSERT_EQ(messages[0].status, LOGIN);


}
