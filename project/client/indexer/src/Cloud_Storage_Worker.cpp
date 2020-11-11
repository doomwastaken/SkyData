#include <utility>

#include "Message.h"
#include "Cloud_Storage_Worker.h"

Cloud_Storage_Worker::Cloud_Storage_Worker(Message message) : m_message(std::move(message)) {

}

int Cloud_Storage_Worker::send_to_cloud(Message& message) {
    return 0;
}
