cmake_minimum_required(VERSION 3.17)
project(queue_tests)

set(CMAKE_CXX_STANDARD 14)

set(GTEST_ROOT /usr/src/googletest/googletest)

find_package( GTest REQUIRED )
include_directories(${GTEST_INCLUDE_DIRS})


include_directories(/usr/src/googletest/googlemock/include/gmock/)
LINK_DIRECTORIES(/usr/src/googletest/googlemock/lib)

include_directories(../../project/libserver/include
                    ../../project/messages
                    ../../project/queue_server/include
                    ../../project/common)

#file(GLOB main_sources "${PROJECT_SOURCE_DIR}/src/queue/Queue.cpp"
#        "${PROJECT_SOURCE_DIR}/src/queue/Vector_Queue.cpp"
#        "${PROJECT_SOURCE_DIR}/src/queue/On_Disk_Saver_Queue.cpp"
#        "${PROJECT_SOURCE_DIR}/src/queue_api/Queue_API.cpp"
#        "${PROJECT_SOURCE_DIR}/src/server/Server.cpp"
#        "${PROJECT_SOURCE_DIR}/src/server/Simple_Server.cpp"
#        "${PROJECT_SOURCE_DIR}/src/socket/Socket.cpp")
#
#file(GLOB test_sources "${PROJECT_SOURCE_DIR}/tests/src/queue_api_tests.cpp"
#        "${PROJECT_SOURCE_DIR}/tests/src/queue_tests.cpp"
#        "${PROJECT_SOURCE_DIR}/tests/src/server_tests.cpp")

set (QUEUE_SRC
        ../../project/queue_server/src/Queue.cpp
        ../../project/queue_server/src/StdQueue.cpp
        ../../project/queue_server/src/OnDiskSaverQueue.cpp
        ../../project/queue_server/src/QueueManager.cpp
        ../../project/queue_server/src/QueueWorker.cpp
        ../../project/queue_server/src/QueueAPI.cpp
        )

set (SERVER_SRC
        ../../project/libserver/src/Connection.cpp
        ../../project/libserver/src/EventLoop.cpp
        ../../project/libserver/src/Master.cpp
        src/queue_api_tests.cpp src/queue_tests.cpp include/master_mock.h src/master_test.cpp)

set (SOCKET_SRC
        ../../project/common/Socket.cpp src/queue_manager_tests.cpp include/event_loop_mock.h)

set (TEST_SRC
        src/queue_api_tests.cpp
        )

add_executable(tests_gmock main.cpp ${SOCKET_SRC} ${QUEUE_SRC} ${SERVER_SRC} ${LIB_SOURCE_FILES})
target_link_libraries(tests_gmock  ${GTEST_LIBRARIES} pthread -lgtest -lgmock)