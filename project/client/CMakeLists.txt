include_directories("indexer/include")
include_directories("../data_bases/Cloud_Storage/include")
include_directories("../data_bases/Internal_DB/include")
include_directories("../messages")


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
        indexer/src/Client_Sender.cpp
        indexer/src/Cloud_Storage_Worker.cpp
        indexer/src/Internal_Data_Base_Worker.cpp
)

set (
        INDEXER_INC
        indexer/include/Client_Sender.h
        indexer/include/Cloud_Storage_Worker.h
        indexer/include/Internal_Data_Base_Worker.h
)

set (
        DB_SRC
        ../data_bases/Cloud_Storage/src/Cloud_Storage_DB.cpp
        ../data_bases/Internal_DB/src/Postgress_Internal_DB.cpp
)

set (
        DB_INC
        ../data_bases/Cloud_Storage/include/Cloud_Storage.h
        ../data_bases/Cloud_Storage/include/Cloud_Storage_DB.h
        ../data_bases/Internal_DB/include/Internal_Data_Base.h
        ../data_bases/Internal_DB/include/Postgress_Internal_DB.h
)

add_executable(project main.cpp ${INDEXER_SRC} ${DB_SRC})
