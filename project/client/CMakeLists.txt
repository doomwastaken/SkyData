include_directories("indexer/include")
include_directories("../data_bases/Cloud_Storage/include")
include_directories("../data_bases/Internal_DB/include")
include_directories("../messages")
include_directories("commander/include")

set (
        INDEXER_SRC
        indexer/src/ClientSender.cpp
        indexer/src/CloudStorageWorker.cpp
        indexer/src/InternalDataBaseWorker.cpp
)

set (
        INDEXER_INC
        indexer/include/ClientSender.h
        indexer/include/CloudStorageWorker.h
        indexer/include/InternalDataBaseWorker.h
)

set (
        DB_SRC
        ../data_bases/Cloud_Storage/src/CloudStorageDB.cpp
        ../data_bases/Internal_DB/src/PostgressInternalDB.cpp
)

set (
        DB_INC
        ../data_bases/Cloud_Storage/include/CloudStorage.h
        ../data_bases/Cloud_Storage/include/CloudStorageDB.h
        ../data_bases/Internal_DB/include/InternalDataBase.h
        ../data_bases/Internal_DB/include/PostgressInternalDB.h
)

set (
        COMMANDER_SRC
        commander/src/ClientSocked.cpp
        commander/src/PushCommand.cpp
        commander/src/PopCommand.cpp
)

set (
        COMMANDER_INC
        commander/include/ClientCommand.h
        commander/include/ClientSocked.h
        commander/include/PushCommand.h
        commander/include/PopCommand.h)

add_executable(project main.cpp ${INDEXER_SRC} ${DB_SRC} ${COMMANDER_SRC} ${COMMANDER_INC})
