include_directories(client/observer/inc)
include_directories(include)

set(    SYNCH_SERV_SRC
        ../data_bases/Metadata_DB/src/Postgress_DB.cpp ../common/Socket.cpp ../common/Socket.h ../libserver/src/Master.cpp ../libserver/include/Master.h ../libserver/src/Connection.cpp ../libserver/include/Connection.h)

include_directories(project/messages)
include_directories(project/data_bases/Metadata_DB/include)

add_executable(synch_service src/main.cpp ${SYNCH_SERV_SRC})
