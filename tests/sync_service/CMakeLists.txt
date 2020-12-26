cmake_minimum_required(VERSION 3.15)
project(test)

set(CMAKE_CXX_STANDARD 14)
set(PROJECT_SOURCE_FILES
        ../../project/data_bases/Metadata_DB/src/PostgressDB.cpp sync_service_test.cpp)
include_directories(../../project/data_bases/Metadata_DB/include)
include_directories(../../project/common)
include_directories(../../project/synchronization_service/include)
include_directories(../../project/libserver/include)


add_executable(tests tests.cpp ${PROJECT_SOURCE_FILES})

target_link_libraries(tests ${GTEST_LIBRARIES} pthread)

