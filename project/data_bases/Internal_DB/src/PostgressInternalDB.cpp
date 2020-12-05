#include "PostgressInternalDB.h"
#include "Message.h"


PostgressInternalDB::PostgressInternalDB() {
}

PostgressInternalDB::~PostgressInternalDB() {
    connect->disconnect();
}

bool PostgressInternalDB::open(const std::string& config) {
    connect = std::make_shared<pqxx::connection>(config);
    return connect->is_open();
}

void PostgressInternalDB::close() {
    connect->disconnect();
}

void PostgressInternalDB::update(Message &message) {

//    const char* sql;

    std::string sql;

    sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "     \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (4, 'Mark', 25, 'Rich-Mond ', 6555000.00 );";

    /* Create a transactional object. */
    pqxx::work W(*connect);

    /* Execute SQL query */
    W.exec( sql );
    W.commit();

}

bool PostgressInternalDB::create_users_table() {
    const char * sql;

    try {
        if (connect->is_open()) {
          //  std::cout << "Opened database successfully: " << connect->dbname() << std::endl;
        } else {
         //   std::cout << "Can't open database\n";
            return true;
        }

        /* Create SQL statement */
        sql = "CREATE TABLE COMPANY("  \
      "ID INT PRIMARY KEY     NOT NULL," \
      "NAME           TEXT    NOT NULL," \
      "AGE            INT     NOT NULL," \
      "ADDRESS        CHAR(50)," \
      "SALARY         REAL );";

        /* Create a transactional object. */
        pqxx::work W(*connect);

        /* Execute SQL query */
        W.exec( sql );
        W.commit();
        std::cout << "Table created successfully" << std::endl;
        //connect->disconnect ();
    } catch (const std::exception &e) {
        //cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
