#include <iostream>
#include "LocalListener.h"
#include "gmock/gmock.h"
#include "gmock/gmock-actions.h"

int main() {
    LocalListener local;
    local.list_local_machine();
    return 0;
}
