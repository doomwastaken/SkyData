cmake_minimum_required(VERSION 3.17)
project(async_client_queue_server)


set(CMAKE_CXX_STANDARD 17)


include_directories(common)
include_directories(libserver/async_server/include)
include_directories(libserver/connection/include)

include_directories(data_bases/MetadataDB/include)

add_subdirectory(Example/Client)
add_subdirectory(Example/Middle)
add_subdirectory(Example/Backend)
add_subdirectory(synchronization_service)
add_subdirectory(libserver)

add_subdirectory(Example/Client_To_Storage)
add_subdirectory(Example/Storage)

#add_subdirectory(queue_server)

