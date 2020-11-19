project(tests)

include_directories(../../../project/client/indexer/include)
include_directories(../../../project/messages)
include_directories(../../../project/data_bases/Cloud_Storage/include)
include_directories(../../../project/data_bases/Internal_DB/include)
include_directories(../../../project/client/commander/include)
include_directories(include)

set (
        TEST_SRC
        main.cpp
        src/utils.cpp
        src/TestClientSender.cpp
        src/TestCloudStorageWorker.cpp
        src/TestInternalDataBaseWorker.cpp
        include/TestCloudStorageWorker.h)

set (
        SRC
        ../../../project/client/indexer/src/ClientSender.cpp
        ../../../project/client/indexer/src/CloudStorageWorker.cpp
        ../../../project/client/indexer/src/InternalDataBaseWorker.cpp
)
add_executable(tests ${TEST_SRC} ${SRC})

target_link_libraries(tests ${GTEST_LIBRARIES} pthread -lgmock)