cmake_minimum_required (VERSION 3.17)

project(libserver)

include_directories(connection/include)
include_directories(async_server/include)

set(SOURCE_FILES
        async_server/src/BackendServer.cpp
        async_server/src/MiddleEnd.cpp
        connection/src/ClientsConnection.cpp
        connection/src/ServerConnection.cpp
        connection/src/ToBackendConnection.cpp)

set(HEADER_FILES
        async_server/include/BackendServer.h
        async_server/include/MiddleEnd.h
        async_server/include/AbstractServer.h
        connection/include/AbstractConnection.h
        connection/include/ClientsConnection.h
        connection/include/ServerConnection.h
        connection/include/ToBackendConnection.h)

add_library(libserver STATIC ${HEADER_FILES} ${SOURCE_FILES})

target_include_directories(libserver PUBLIC connection async_server)
