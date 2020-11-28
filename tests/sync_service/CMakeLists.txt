cmake_minimum_required(VERSION 3.15)
project(tests_sync)

set(CMAKE_CXX_STANDARD 14)
set(PROJECT_SOURCE_FILES
        ../../project/data_bases/Metadata_DB/src/PostgressDB.cpp sync_service_test.cpp)
include_directories(../../project/data_bases/Metadata_DB/include)
include_directories(../../project/messages)
include_directories(../../project/synchronization_service/include)
include_directories(../../project/libserver/include)
include_directories(../../project/common)


add_executable(tests_sync tests.cpp ${PROJECT_SOURCE_FILES} metadata_db_test.cpp sync_service_test.cpp)

target_link_libraries(tests_sync ${GTEST_LIBRARIES} pthread -lgmock)

