#ifndef PROJECT_CLIENT_OBSERVER_LOCAL_LISTENER_H
#define PROJECT_CLIENT_OBSERVER_LOCAL_LISTENER_H
#include "iostream"
#include "Message.h"
#include "EventListen.h"
#include "../liblistener/include/Listener.h"
#include "MessageUpdater.h"

class NotificationReceiver : public std::enable_shared_from_this<NotificationReceiver>
{
public:
    // Callback
    void OnFilePathChanged(
            const gogo::FilePath& path,
            bool error,
            gogo::FilePathWatcher::Event event);

};


class LocalListener : public EventListen{
    static std::shared_ptr<Message> create_message(std::string path, gogo::FilePathWatcher::Event event);
   // std::shared_ptr<Message> message;
    static long get_file_size(std::string filename);
    friend NotificationReceiver;


public:

    int event_listen(const std::string& path_str, const std::string& user_name,
                     const std::string&, const std::string&, int, const std::string&) override;
};




#endif //PROJECT_CLIENT_LOCAL_LISTENER_H
