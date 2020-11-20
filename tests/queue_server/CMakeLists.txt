project(tests_queue_server)

include_directories(../../../project/queue_server/include)
include_directories(../../../project/messages)
include_directories(../../../project/libserver/include)
include_directories(include)

set (
        TEST_SRC
        main.cpp
        src/utils.cpp
        src/TestClientSender.cpp
        src/TestCloudStorageWorker.cpp
        src/TestInternalDataBaseWorker.cpp
)

set (
        SRC
        ../../../project/client/indexer/src/ClientSender.cpp
        ../../../project/client/indexer/src/CloudStorageWorker.cpp
        ../../../project/client/indexer/src/InternalDataBaseWorker.cpp
)

add_executable(tests_indexer ${TEST_SRC} ${SRC})

target_link_libraries(tests_indexer ${GTEST_LIBRARIES} pthread -lgmock)