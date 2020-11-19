#include <iostream>
#include "LocalListener.h"
#include "Downloader.h"
#include "EventEditor.h"
#include "Observer.h"
#include "MessageUpdater.h"
#include "MessageListener.h"

int main() {
    LocalListener local;
    local.event();
    Observer observer;
    observer.update_client();
    return 0;
}
