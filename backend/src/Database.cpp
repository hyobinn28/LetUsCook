#include "Database.h"
#include <iostream>

using namespace std;

Database::Database() {
    try {
        session = new mysqlx::Session("localhost", 33060, "user", "password");
        schema = new mysqlx::Schema(session->getSchema("let_us_cook"));
    }
    catch (const mysqlx::Error &err) {
        cerr << "MySQL session error: " << err.what() << endl;
    }
    catch (std::exception &ex) {
        cerr << "STD exception: " << ex.what() << endl;
    }
    catch (const char *ex) {
        cerr << "Error: " << ex << endl;
    }
}

Database::~Database() {
    delete schema;
    delete session;
}

bool Database::execute(const string& query) {
    try {
        session->sql(query).execute();
        return true;
    } 
    catch (const mysqlx::Error &err) {
        cerr << "SQL execution error: " << err.what() << endl;
        return false;
    }
}

vector<map<string, string>> Database::query(const string& query) {
    vector<map<string, string>> results;
    try {
        mysqlx::SqlResult result = session->sql(query).execute();
        mysqlx::Row row;

        while((row = result.fetchOne())) {
            map<string, string> rowMap;
            for(size_t i = 0; i < row.colCount(); ++i) {
                rowMap[result.getColumn(i).getColumnName()] = row[i].get<string>();
            }
            results.push_back(rowMap);
        }
    }
    catch(const mysqlx::Error &err) {
        cerr << "SQL query error: " << err.what() << endl;
    }
    return results;
}

int Database::getLastInsertId() {
    try {
        mysqlx::SqlResult result = session->sql("SELECT LAST_INSERT_ID()").execute();
        mysqlx::Row row = result.fetchOne();
        return row[0].get<int>();
    }
    catch (const mysqlx::Error &err) {
        cerr << "SQL get last insert ID error: " << err.what() << endl;
        return -1;
    }
}
