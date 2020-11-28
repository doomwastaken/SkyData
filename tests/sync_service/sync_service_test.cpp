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

class MockDatabaseWorker {
public:
    MOCK_METHOD(void, run, (), ());
    MOCK_METHOD(void, take_task, (), ());
    MOCK_METHOD(void, do_task, (), ());
};

template<class Type>
class MockDatabase {
public:
    explicit MockDatabase(Type* val) : value(val) { }

    void run_test() {
        value->run();
    }
    void take_task_test() {
        value->take_task();
    }
    void do_task_test() {
        value->do_task();
    }

private:
    Type* value;
};

TEST(test_worker, test1) {
    MockDatabaseWorker worker;

    EXPECT_CALL(worker, run()).Times(1);

    MockDatabase<MockDatabaseWorker> data(&worker);
    data.run_test();
}

TEST(test_worker, test2) {
    MockDatabaseWorker worker;

    EXPECT_CALL(worker, take_task()).Times(1);

    MockDatabase<MockDatabaseWorker> data(&worker);
    data.take_task_test();
}

TEST(test_worker, test3) {
    MockDatabaseWorker worker;

    EXPECT_CALL(worker, do_task()).Times(1);

    MockDatabase<MockDatabaseWorker> data(&worker);
    data.do_task_test();
}
