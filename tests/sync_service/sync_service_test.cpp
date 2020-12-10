#include <fstream>
#include <iostream>
#include <sstream>
#include <random>

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "PostgressDB.h"
#include "Sync_Service.h"

using ::testing::_;
using ::testing::AtLeast;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::SetArgReferee;

unsigned long random(unsigned int begin, unsigned int end) {
    std::random_device rd;
    std::mt19937 gener(rd());
    std::uniform_int_distribution<unsigned int> dist(begin, end);
    return dist(rd);
}

std::string random_str_gen(int length) {
    static std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    std::string result;
    result.resize(length);

    for (int i = 0; i < length; i++)
        result[i] = charset[random(0, charset.length())];

    return result;
}

class MockDatabase : public Postgress_DB {
public:
    MOCK_METHOD(bool, update, (Message & message, std::vector<Message> & result), (override));
};

class Mock_Queue : public Queue_Api {
public:
    MOCK_METHOD(void, push_to_queue, (Message &message), ());
    MOCK_METHOD(Message, pop_from_queue, (), ());
};

TEST(test_listener, test1) {
    MockDatabase database;
    Mock_Queue queue;
    Sync_Service sync(database, queue);
    devise_t devise = {random_str_gen(7), random_str_gen(7)};
    user_t user = {random_str_gen(7), random_str_gen(7), devise, 5};
    Message message = {100, MODIFIED, 0, 2, random_str_gen(7),
                       random_str_gen(7), 100, random_str_gen(7), user};
    std::vector<Message> vector_mes;
    vector_mes.push_back(message);
    EXPECT_CALL(database, update(_, vector_mes))
            .WillOnce(DoAll(SetArgReferee<1>(vector_mes), Return(true)));

    sync.listen();
}

TEST(test_listener, test2) {
    MockDatabase database;
    Mock_Queue queue;
    Sync_Service sync(database, queue);
    devise_t devise = {random_str_gen(7), random_str_gen(7)};
    user_t user = {random_str_gen(7), random_str_gen(7), devise, 5};
    Message message = {100, MODIFIED, 0, 2, random_str_gen(7),
                       random_str_gen(7), 100, random_str_gen(7), user};
    std::vector<Message> vector_mes;
    vector_mes.push_back(message);
    EXPECT_CALL(queue, push_to_queue(message))
            .Times(1);
    sync.listen();
}

TEST(test_listener, test3) {
    MockDatabase database;
    Mock_Queue queue;
    Sync_Service sync(database, queue);
    devise_t devise = {random_str_gen(7), random_str_gen(7)};
    user_t user = {random_str_gen(7), random_str_gen(7), devise, 5};
    Message message = {100, MODIFIED, 0, 2, random_str_gen(7),
                       random_str_gen(7), 100, random_str_gen(7), user};
    std::vector<Message> vector_mes;
    vector_mes.push_back(message);
    EXPECT_CALL(queue, pop_from_queue())
            .WillOnce(DoAll(Return(message)));
    sync.listen();
}