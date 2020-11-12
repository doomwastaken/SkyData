
#include "iostream"
#include "gtest/gtest.h"
#include "Observer.h"
#include "Local_Listener.h"
#include "Message_Listener.h"
#include "Message_Updater.h"
#include "Cloud_Storage_Downloader.h"
#include "messages.h"
#include <random>
#include "utils.h"


// Проверяет получение достоверность сообщения, полученного из очереди и записанного в message
TEST(ListenerTest, test_on_listen_queue) {
    Message_Listener message_listener;
    devise_t devise = {random_str_gen(7), random_str_gen(7)};
    user_t user = {random_str_gen(7), random_str_gen(7), devise, 5};
    Message message = {100, MODIFIED, 0, 2, random_str_gen(7),
                       random_str_gen(7), 100, random_str_gen(7), user};
    Message message1 = message_listener.to_listen_message();

    EXPECT_TRUE(message1 == message);

}
// Проверяет получение достоверность сообщения, полученного с локальной машины и записанного в message
TEST(LocalListenerTest, test_on_listen_queue) {
    Local_Listener message_listener;
    devise_t devise = {random_str_gen(7), random_str_gen(7)};
    user_t user = {random_str_gen(7), random_str_gen(7), devise, 7};
    Message message = {my_random(0,200), MODIFIED, 0, 2, random_str_gen(7),
                       random_str_gen(7), my_random(0,200), random_str_gen(7), user};
    Message message1 = message_listener.list_local_machine();

    EXPECT_TRUE(message1 == message);
}

// Проверяет правильность выполнения класса, передающего информацию обсерверу, которую нужно скачать пользователю
TEST(Downloader, test) {
    Cloud_Storage_Downloader<std::string> downloader;
    std::string path_to_local_file = random_str_gen(7);
    EXPECT_EQ(downloader.downloader_files_from_cloud(path_to_local_file), 0) ;

}

// Проверяет правильность выполнения главного класса, который скачивает файл на локальную машину из облака
TEST(Observer, test_of_load) {
    Observer<std::string> observer;
    EXPECT_EQ(observer.load_to_machine(), 0);

}



int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}