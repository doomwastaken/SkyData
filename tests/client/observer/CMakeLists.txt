include_directories(../../../project/client/observer/include)
include_directories("../../../project/common")
include_directories(./project/client/observer)
include_directories(../../../project/client/indexer/include)
include_directories(../../../project/data_bases/Cloud_Storage/include)
include_directories(../../../project/data_bases/Internal_DB/include)
include_directories(../../../project/client/commander/include)


set (
        OBSERVER_SRC
        ../../../project/client/observer/src/LocalListener.cpp
        ../../../project/client/observer/src/Observer.cpp
        ../../../project/client/observer/src/MessageListener.cpp
        ../../../project/client/observer/src/MessageUpdater.cpp
        ../../../project/client/observer/src/Downloader.cpp
)

set (
        SRC
        ../../../project/client/indexer/src/ClientSender.cpp
        ../../../project/client/indexer/src/CloudStorageWorker.cpp
        ../../../project/client/indexer/src/InternalDataBaseWorker.cpp
)


add_executable(tests_observer tests_observer.cpp utils.cpp ${LIB_SOURCE_FILES} ${OBSERVER_SRC} ${SRC})

target_link_libraries(tests_observer ${GTEST_LIBRARIES} pthread -lgmock)