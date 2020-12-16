cmake_minimum_required(VERSION 3.17)
project(server_backend)

set(CMAKE_CXX_STANDARD 17)

<<<<<<< HEAD
add_executable(server_backend main.cpp)

find_package(Boost COMPONENTS thread system serialization REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
=======
set (QUEUE_SRC
        ../../queue_server/src/StdQueue.cpp
        ../../queue_server/src/OnDiskSaverQueue.cpp
        ../../queue_server/src/QueueManager.cpp
        )

add_executable(server_backend main.cpp ${QUEUE_SRC})

find_package(Boost COMPONENTS thread system serialization REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
include_directories(../../queue_server/include)
>>>>>>> development

target_link_libraries(server_backend ${Boost_LIBRARIES} libserver)