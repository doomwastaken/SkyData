cmake_minimum_required(VERSION 3.17)
project(server_middle)

set(CMAKE_CXX_STANDARD 17)

add_executable(server_middle main.cpp
        ../../server/middle_end/middle_end.cpp
        ../../connection/server_connection/server_connection.cpp
        ../../connection/to_backend_connection/to_backend_connection.cpp)

find_package(Boost COMPONENTS thread system serialization REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
target_link_libraries(server_middle ${Boost_LIBRARIES})