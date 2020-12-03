cmake_minimum_required(VERSION 3.17)
project(queue_server)

include_directories(../messages)
include_directories(../libserver/include)
include_directories(../common)
include_directories(include)

set (QUEUE_SRC
        src/Queue.cpp
        src/StdQueue.cpp
        src/OnDiskSaverQueue.cpp
        src/QueueManager.cpp
        src/QueueWorker.cpp
        src/QueueAPI.cpp
)

set (SERVER_SRC
        ../libserver/src/Connection.cpp
        ../libserver/src/EventLoop.cpp
        ../libserver/src/Master.cpp
        )

add_executable(queue_server main.cpp ${QUEUE_SRC} ${SERVER_SRC})
