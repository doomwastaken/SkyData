#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <filesystem>

#include "ClientToStorageConnection.h"
#include "ClientSender.h"
#include "ClientsConnection.h"

using boost::asio::ip::tcp;

int ClientSender::send(std::shared_ptr<Message> &message, ClientsConnection &cl_con,
                       ClientToStorageConnection &storage_conn, event_BD event_bd) {
    if (m_internal_db.send_meta_data(message)) {
        // TODO: Добавить логирование
        return 1;
    }
    std::cout << "send_meta_data" << std::endl;

    if (event_bd == ONLY_SQL) {
        if (message->status != DELETE) {
            m_cloud_storage.download_from_cloud(message, storage_conn);
        } else {
            std::cout << "TRYING TO DELETE: " << message->user.devise.sync_folder + "/" +
                                                 message->file_path + "/" + message->file_name +
                                                 message->file_extension << std::endl;
            std::filesystem::remove(message->user.devise.sync_folder + "/" +
                                       message->file_path + "/" + message->file_name +
                                       message->file_extension);
        }
        return EXIT_SUCCESS;
    } else if (message->status == DELETE) {
        m_cloud_storage.remove_from_cloud(message, storage_conn);
    }
    else if (m_cloud_storage.send_to_cloud(message, storage_conn)) {
        // TODO: Добавить логирование
        return 1;
    }
    std::cout << message->status << " MES_STATUS\n";
    std::cout << "send_to_cloud" << std::endl;


    cl_con.write(*message);
    std::cout << "write" << std::endl;
    // TODO: Добавить логировани
    return 0;
}