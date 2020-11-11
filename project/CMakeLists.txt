include_directories("client/indexer/include")
include_directories("data_bases/Cloud_Storage/include")
include_directories("data_bases/Internal_DB/include")
include_directories("messages")


set (
        OBSERBER_SRC
        client/observer/src/local_listener.cpp
        client/observer/src/observer.cpp
        client/observer/src/message_listener.cpp
        client/observer/src/message_updater.cpp
        client/observer/src/cloud_storage_downloader.cpp
)

set (
        INDEXER_SRC
        client/indexer/src/Client_Sender.cpp
        client/indexer/src/Cloud_Storage_Worker.cpp
        client/indexer/src/Internal_Data_Base_Worker.cpp
)

set (
        INDEXER_INC
        client/indexer/include/Client_Sender.h
        client/indexer/include/Cloud_Storage_Worker.h
        client/indexer/include/Internal_Data_Base_Worker.h
)

add_executable(project main.cpp ${INDEXER_SRC})
