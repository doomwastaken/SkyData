#include <fstream>
#include <iostream>

#include "gtest/gtest.h"
#include "PostgressDB.h"


TEST(connection_test, test1) {
    std::ofstream cerr_file("CERR_LOG.txt");
    std::cerr.rdbuf(cerr_file.rdbuf());

    Postgress_DB postgress_db;
    cerr_file.close();

    std::ifstream cerr_file_read("CERR_LOG.txt");
    std::string line;
    std::stringstream error_stream;

    if (cerr_file_read.is_open()) {
        while (std::getline(cerr_file_read, line)) {
            error_stream << line;
        }
        cerr_file_read.close();
    }
    ASSERT_NE(error_stream.str(), "Not connected");
}

