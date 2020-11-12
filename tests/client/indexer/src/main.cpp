#include "gtest/gtest.h"

#include "Cloud_Storage_Worker.h"
#include "Internal_Data_Base_Worker.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
