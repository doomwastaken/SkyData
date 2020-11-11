include_directories(client/observer/include)
include_directories("messages")


set (
        OBSERVER_SRC
        client/observer/src/Local_Listener.cpp
        client/observer/src/Observer.cpp
        client/observer/src/Message_Listener.cpp
        client/observer/src/Message_Updater.cpp
        client/observer/src/Cloud_Storage_Downloader.cpp

)


add_executable(project main.cpp ${OBSERVER_SRC})
