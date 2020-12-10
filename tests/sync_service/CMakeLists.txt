cmake_minimum_required(VERSION 3.15)
project(test)

set(CMAKE_CXX_STANDARD 14)
set(PROJECT_SOURCE_FILES
        ../../project/data_bases/MetadataDB/src/PostgressDB.cpp sync_service_test.cpp)
        
include_directories(../../project/data_bases/MetadataDB/include)
include_directories(../../project/messages)
include_directories(../../project/synchronization_service/include)
include_directories(../../project/libserver/include)


add_executable(tests tests.cpp ${PROJECT_SOURCE_FILES} metadata_db_test.cpp sync_service_test.cpp)

target_link_libraries(tests ${GTEST_LIBRARIES} pthread)

