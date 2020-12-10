cmake_minimum_required(VERSION 3.17)
project(project)

set(CMAKE_CXX_STANDARD 17)
#SET(GCC_COVERAGE_COMPILE_FLAGS "--coverage ")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  ")

#add_compile_options("--coverage")
#add_link_options("--coverage")

find_package(GTest  REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_subdirectory(tests/client/indexer)
add_subdirectory(tests/client/observer)
enable_testing()

add_subdirectory(project)
add_subdirectory(tests)
