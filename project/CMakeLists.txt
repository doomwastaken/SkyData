cmake_minimum_required(VERSION 3.17)
project(async_client_queue_server)

set(CMAKE_CXX_STANDARD 14)

include_directories(common)
include_directories(libserver/async_server/include)
include_directories(libserver/connection/include)

include_directories(data_bases/Cloud_Storage/include)
include_directories(data_bases/Internal_DB/include)
include_directories(data_bases/Metadata_DB/include)

include_directories(client/commander/include)
include_directories(client/observer/include)
include_directories(client/indexer/include)
include_directories(messages)

add_subdirectory(Example/Client)
add_subdirectory(client)
add_subdirectory(Example/Middle)
add_subdirectory(Example/Backend)
add_subdirectory(libserver)
