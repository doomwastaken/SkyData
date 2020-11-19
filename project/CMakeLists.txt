include_directories(client/observer/include)
include_directories("messages")


set (
        OBSERVER_SRC
        client/observer/src/LocalListener.cpp
        client/observer/src/Observer.cpp
        client/observer/src/MessageListener.cpp
        client/observer/src/MessageUpdater.cpp
        client/observer/src/Downloader.cpp
        client/observer/src/EventEditor.cpp

)


add_executable(project main.cpp ${OBSERVER_SRC})
