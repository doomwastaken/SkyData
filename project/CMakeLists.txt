include_directories("data_bases/Cloud_Storage/include")
include_directories("data_bases/Internal_DB/include")

include_directories("messages")

include_directories("client/commander/include")
include_directories(client/observer/include)
include_directories("client/indexer/include")


set (
        INDEXER_SRC
        client/indexer/src/ClientSender.cpp
        client/indexer/src/CloudStorageWorker.cpp
        client/indexer/src/InternalDataBaseWorker.cpp
)

set (
        INDEXER_INC
        client/indexer/include/ClientSender.h
        client/indexer/include/CloudStorageWorker.h
        client/indexer/include/InternalDataBaseWorker.h
)

set (
        DB_SRC
        data_bases/Cloud_Storage/src/CloudStorageDB.cpp
        data_bases/Internal_DB/src/PostgressInternalDB.cpp
)

set (
        DB_INC
        data_bases/Cloud_Storage/include/CloudStorage.h
        data_bases/Cloud_Storage/include/CloudStorageDB.h
        data_bases/Internal_DB/include/InternalDataBase.h
        data_bases/Internal_DB/include/PostgressInternalDB.h
)

set (
        COMMANDER_SRC
        client/commander/src/ClientSocked.cpp
        client/commander/src/PushCommand.cpp
        client/commander/src/PopCommand.cpp
)

set (
        COMMANDER_INC
        client/commander/include/ClientCommand.h
        client/commander/include/ClientSocked.h
        client/commander/include/PushCommand.h
        client/commander/include/PopCommand.h)

set (
        OBSERVER_SRC
        client/observer/src/LocalListener.cpp
        client/observer/src/Observer.cpp
        client/observer/src/MessageListener.cpp
        client/observer/src/MessageUpdater.cpp
        client/observer/src/Downloader.cpp
        client/observer/src/EventEditor.cpp
)

set (
        DATABASE_SRC
        data_bases/Cloud_Storage/src/CloudStorageDB.cpp
        data_bases/Internal_DB/src/PostgressInternalDB.cpp
)

add_executable(project main.cpp ${INDEXER_SRC} ${DB_SRC} ${COMMANDER_SRC} ${COMMANDER_INC} ${OBSERVER_SRC} ${DATABASE_SRC})
