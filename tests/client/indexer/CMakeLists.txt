project(tests_gmock)

include_directories(../../../project/client/indexer/include)
include_directories(../../../project/messages)
include_directories(../../../project/data_bases/Cloud_Storage/include)
include_directories(../../../project/data_bases/Internal_DB/include)
include_directories(include)

set (
        TEST_SRC
        src/main.cpp
        src/utils.cpp
        src/test_client_sender.cpp
        src/test_cloud_storage_worker.cpp
        src/test_internal_data_base_worker.cpp
)
add_executable(tests_gmock ${TEST_SRC})

target_link_libraries(tests_gmock ${GTEST_LIBRARIES} pthread -lgmock)