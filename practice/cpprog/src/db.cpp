#include <iostream>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

int main() {
    try {
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;

        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "user", "password");
        con->setSchema("your_database_name");

        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT * FROM your_table_name");

        while (res->next()) {
            std::cout << res->getInt("id") << " " << res->getString("name") << std::endl;
        }

        delete res;
        delete stmt;
        delete con;
    } catch (sql::SQLException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
