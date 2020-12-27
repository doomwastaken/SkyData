
cmake_minimum_required(VERSION 3.17)
project(project)

set(CMAKE_CXX_STANDARD 17)
#SET(GCC_COVERAGE_COMPILE_FLAGS "--coverage ")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  ")

#add_compile_optioкуафns("--coverage")
#add_link_options("--coverage")

find_package(GTest  REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
find_package(Boost COMPONENTS thread system serialization REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

#add_subdirectory(tests/client/indexer)
#add_subdirectory(tests/client/observer)
enable_testing()

add_subdirectory(project)
add_subdirectory(tests)