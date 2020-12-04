include_directories(client/observer/inc)
include_directories(include)

set(    SYNCH_SERV_SRC
        ../data_bases/Metadata_DB/src/Postgress_DB.cpp)

include_directories(project/messages)
include_directories(project/data_bases/Metadata_DB/include)

add_executable(synch_service src/main.cpp ${SYNCH_SERV_SRC})
