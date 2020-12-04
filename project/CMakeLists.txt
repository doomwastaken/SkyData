cmake_minimum_required(VERSION 3.17)
project(async_client_queue_server)

set(CMAKE_CXX_STANDARD 14)

include_directories(common)
include_directories(libserver/async_server/include)
include_directories(libserver/connection/include)

add_subdirectory(Example/Client)
add_subdirectory(Example/Middle)
add_subdirectory(Example/Backend)
add_subdirectory(libserver)
