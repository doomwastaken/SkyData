

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

set (
        OBSERVER_SRC
        observer/src/LocalListener.cpp
        observer/src/Observer.cpp
        observer/src/MessageListener.cpp
        observer/src/MessageUpdater.cpp
        observer/src/Downloader.cpp
        observer/src/EventListen.cpp
)

set (
        INDEXER_SRC
        indexer/src/ClientSender.cpp
        indexer/src/CloudStorageWorker.cpp
        indexer/src/InternalDataBaseWorker.cpp
)

set (
        DATABASE_SRC
        ../data_bases/Cloud_Storage/src/CloudStorageDB.cpp
        ../data_bases/Internal_DB/src/SQLite.cpp
        ../queue_server/main.cpp)

add_executable(client_nash main.cpp ${INDEXER_SRC} ${DB_SRC} ${COMMANDER_SRC} ${COMMANDER_INC} ${OBSERVER_SRC} ${DATABASE_SRC})
target_link_libraries(client_nash ${Boost_LIBRARIES} libserver sqlite3)