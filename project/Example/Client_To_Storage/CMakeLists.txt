cmake_minimum_required(VERSION 3.17)
project(client_to_storage)

set(CMAKE_CXX_STANDARD 17)

add_executable(client_to_storage main.cpp)

find_package(Boost COMPONENTS thread system serialization REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

target_link_libraries(client_to_storage ${Boost_LIBRARIES} libserver)
