#include <iostream>
#include "Local_Listener.h"
#include "gmock/gmock.h"
#include "gmock/gmock-actions.h"

int main() {
    Local_Listener local;
    local.list_local_machine();
    return 0;
}
