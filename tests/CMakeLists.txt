
include_directories(../project/client/observer/include)
include_directories("../project/messages")
include_directories(./project/client/observer)


set (
        OBSERVER_SRC
        ../project/client/observer/src/Local_Listener.cpp
        ../project/client/observer/src/Observer.cpp
        ../project/client/observer/src/Message_Listener.cpp
        ../project/client/observer/src/Message_Updater.cpp
        ../project/client/observer/src/Cloud_Storage_Downloader.cpp
)


add_executable(tests_gmock client/observer/tests_gmock.cpp client/observer/utils.cpp ${LIB_SOURCE_FILES} ${OBSERVER_SRC})

target_link_libraries(tests_gmock ${GTEST_LIBRARIES} pthread -lgmock)