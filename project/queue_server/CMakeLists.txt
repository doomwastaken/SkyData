cmake_minimum_required(VERSION 3.17)
project(queue_server)

include_directories(../common)
include_directories(../libserver/include)
include_directories(../common)
include_directories(include)

set (QUEUE_SRC
        src/StdQueue.cpp
        src/QueueManager.cpp
        )

add_executable(queue_server main.cpp ${QUEUE_SRC} ${SERVER_SRC})

find_package(Boost COMPONENTS thread system serialization REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
target_link_libraries(queue_server ${Boost_LIBRARIES} libserver)
