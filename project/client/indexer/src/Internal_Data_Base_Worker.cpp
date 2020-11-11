#include "Message.h"
#include "Internal_Data_Base_Worker.h"

Internal_Data_Base_Worker::Internal_Data_Base_Worker(Message &message) : message(message) {

}

int Internal_Data_Base_Worker::send_to_data_base(Message& mes) {
    return 0;
}