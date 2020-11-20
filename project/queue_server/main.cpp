#include "Master.h"
#include "Event.h"

int main(int argc, char** argv) {
    //Master master(std::atoi(argv[1]));
    Master master(777);
    master.run_server();
    return 0;
}