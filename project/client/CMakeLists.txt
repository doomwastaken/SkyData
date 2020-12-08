set (
        INDEXER_SRC
        indexer/src/ClientSender.cpp
        indexer/src/CloudStorageWorker.cpp
        indexer/src/InternalDataBaseWorker.cpp
)

set (
        OBSERVER_SRC
        observer/src/LocalListener.cpp
        observer/src/Observer.cpp
        observer/src/MessageListener.cpp
        observer/src/MessageUpdater.cpp
        observer/src/Downloader.cpp
        observer/src/EventListen.cpp
)

add_executable(client_nash main.cpp ${INDEXER_SRC} ${OBSERVER_SRC} ${DATABASE_SRC})
target_link_libraries(client_nash ${Boost_LIBRARIES} libserver)