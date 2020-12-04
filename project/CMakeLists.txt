cmake_minimum_required(VERSION 3.17)
project(async_client_queue_server)

set(CMAKE_CXX_STANDARD 14)

include_directories(common)
include_directories(server)

add_subdirectory(Example/Client)
add_subdirectory(Example/Middle)
add_subdirectory(Example/Backend)