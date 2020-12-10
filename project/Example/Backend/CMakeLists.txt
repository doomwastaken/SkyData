cmake_minimum_required(VERSION 3.17)
project(server_backend)

set(CMAKE_CXX_STANDARD 17)

add_executable(server_backend main.cpp)


find_library(PQXX_LIB pqxx)
find_library(PQ_LIB pq)
find_package(Boost COMPONENTS thread system serialization REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

target_link_libraries(server_backend ${PQXX_LIB} ${PQ_LIB} ${Boost_LIBRARIES} libserver)