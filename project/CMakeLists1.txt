include_directories(data_bases/Cloud_Storage/include)
include_directories(data_bases/Internal_DB/include)

include_directories(client/commander/include)
include_directories(client/observer/include)
include_directories(client/indexer/include)

include_directories(messages)
include_directories(data_bases/Metadata_DB/include)
include_directories(common)
include_directories(libserver/include)

add_subdirectory(synchronization_service)
add_subdirectory(client)
add_subdirectory(queue_server)
