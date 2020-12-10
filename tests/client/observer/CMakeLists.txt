include_directories(../../../project/client/observer/include)
include_directories("../../../project/common")
include_directories(./project/client/observer)


set (
        OBSERVER_SRC
        ../../../project/client/observer/src/LocalListener.cpp
        ../../../project/client/observer/src/Observer.cpp
        ../../../project/client/observer/src/MessageListener.cpp
        ../../../project/client/observer/src/MessageUpdater.cpp
        ../../../project/client/observer/src/Downloader.cpp
)


add_executable(tests_observer tests_observer.cpp utils.cpp ${LIB_SOURCE_FILES} ${OBSERVER_SRC})

target_link_libraries(tests_observer ${GTEST_LIBRARIES} pthread -lgmock)