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
    MOCK_METHOD(pqxx::result, select, (const std::string str));
    MOCK_METHOD(void, insert_devise, (Message &message));
    MOCK_METHOD(void, insert_file, (Message &message));
    MOCK_METHOD(void, erase, (Message &message));
    MOCK_METHOD(void, modified, (Message &message));
};

TEST(test_update, test_login) {
    MockDatabase db;
    Message message;
    message.status = LOGIN;
    message.user.devise.device_name = "Mac";
    std::string quote = "'";
    const std::string first_arg = "SELECT * from USERS_DEVISES "
                    "WHERE device_name = " + quote + message.user.devise.device_name + quote;


    EXPECT_CALL(db, select(first_arg))
            .Times(1);

    EXPECT_CALL(db, insert_devise(message))
            .Times(1);
}

TEST(test_update, test_create) {
    MockDatabase db;
    Message message;
    message.status = CREATE;
    message.user.devise.device_name = "Mac";

    EXPECT_CALL(db, select(_))
            .Times(2);

    EXPECT_CALL(db, insert_file(message))
            .Times(1);
}

TEST(test_update, test_delete) {
    MockDatabase db;
    Message message;
    message.status = DELETE;
    message.user.devise.device_name = "Mac";

    EXPECT_CALL(db, select(_))
            .Times(1);

    EXPECT_CALL(db, erase(message))
            .Times(1);
}

TEST(test_update, test_modified) {
    MockDatabase db;
    Message message;
    message.status = MODIFIED;
    message.user.devise.device_name = "Mac";

    EXPECT_CALL(db, select(_))
            .Times(1);

    EXPECT_CALL(db, modified(message))
            .Times(1);
}
