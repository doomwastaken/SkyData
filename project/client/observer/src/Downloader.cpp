#include "Downloader.h"

template<class T>
int Downloader<T>::downloader_files_from_cloud(Message message) {
    return 0;
}

template<class T>
Message Downloader<T>::push() {
    return messages[0];
}

template<class T>
Message Downloader<T>::pop() {
    return messages[0];
}


