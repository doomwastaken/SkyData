include_directories(client/observer/include)
include_directories("messages")
include_directories("data_bases/Cloud_Storage/include")
include_directories("data_bases/Internal_DB/include")


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


add_executable(project main.cpp ${OBSERVER_SRC} ${DATABASE_SRC})
