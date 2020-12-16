#include <fstream>
#include <iostream>
#include <sstream>
#include <random>
#include <queue>

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "PostgressDB.h"
#include "DataBaseWorker.h"
#include "Event.h"

using ::testing::_;
using ::testing::AtLeast;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::SetArgReferee;

class MockDatabaseWorker: public DataBaseWorker {
    MOCK_METHOD(void, run, (), ());
    MOCK_METHOD(void, take_task, (), ());
    MOCK_METHOD(void, do_task, (), ());
};

TEST(test_worker, test1) {
    PostgressDB data_base;
    std::queue<Event> m_clients_have_work;
    std::shared_ptr<std::mutex> m_have_work_mutex;
    MockDatabaseWorker worker(data_base, m_clients_have_work, m_have_work_mutex);
    EXPECT_CALL(worker, run())
            .Times(1);
}

TEST(test_worker, test2) {
    PostgressDB data_base;
    std::queue<Event> m_clients_have_work;
    std::shared_ptr<std::mutex> m_have_work_mutex;
    MockDatabaseWorker worker(data_base, m_clients_have_work, m_have_work_mutex);
    EXPECT_CALL(worker, take_task())
            .Times(1);
}

TEST(test_worker, test3) {
    PostgressDB data_base;
    std::queue<Event> m_clients_have_work;
    std::shared_ptr<std::mutex> m_have_work_mutex;
    MockDatabaseWorker worker(data_base, m_clients_have_work, m_have_work_mutex);
    EXPECT_CALL(worker, do_task())
            .Times(1);
}
