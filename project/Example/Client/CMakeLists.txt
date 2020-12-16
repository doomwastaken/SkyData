cmake_minimum_required(VERSION 3.17)
project(client)


set (
        OBSERVER_SRC
        ../../client/observer/src/LocalListener.cpp
        ../../client/observer/src/Observer.cpp
        ../../client/observer/src/MessageListener.cpp
        ../../client/observer/src/MessageUpdater.cpp
        ../../client/observer/src/Downloader.cpp
        ../../client/observer/src/EventListen.cpp
)

set (
        INDEXER_SRC
        ../../client/indexer/src/ClientSender.cpp
        ../../client/indexer/src/CloudStorageWorker.cpp
        ../../client/indexer/src/InternalDataBaseWorker.cpp
)

set (
        DATABASE_SRC
        ../../data_bases/Cloud_Storage/src/CloudStorageDB.cpp
        ../../data_bases/Internal_DB/src/SQLite.cpp
        ../../queue_server/main.cpp)

add_executable(client main.cpp ${INDEXER_SRC} ${DB_SRC} ${OBSERVER_SRC} ${DATABASE_SRC} ../../common/Message.cpp)
target_link_libraries(client ${Boost_LIBRARIES} libserver sqlite3 liblistener)
