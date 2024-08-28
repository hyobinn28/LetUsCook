#include "Database.h"
#include <iostream>

using namespace std;

Database::Database() {
    try {
        //mysql credential
        session = new mysqlx::Session("localhost", 33060, "root", "stella3110");   
        session->sql("USE let_us_cook").execute(); 
        schema = new mysqlx::Schema(session->getSchema("let_us_cook"));

        if(schema->existsInDatabase()) {
            cout << "Connected to database let_us_cook successfully." << endl;
        }
        else {
            cerr << "Failed to connect to the database let_us_cook." << endl;
        }
    }
    catch(const mysqlx::Error &err) {
        cerr << "MySQL session error: " << err.what() << endl;
    }
    catch(exception &ex) {
        cerr << "STD exception: " << ex.what() << endl;
    }
    catch (const char *ex) {
        cerr << "Error: " << ex << endl;
    }
}

Database::~Database() {
    if (schema) delete schema;
    if (session) delete session;
}

bool Database::execute(const string &query) {
    try {
        session->sql(query).execute();
        return true;
    } 
    catch (const mysqlx::Error &err) {
        cerr << "SQL execution error: " << err.what() << endl;
        return false;
    }
}

vector<map<string, string>> Database::query(const string &query) {
    vector<map<string, string>> results;
    try {
        mysqlx::SqlResult result = session->sql(query).execute();
        mysqlx::Row row;

        while((row = result.fetchOne())) {
            map<string, string> rowMap;
            for (size_t i = 0; i < row.colCount(); ++i) {
                string columnName = result.getColumn(i).getColumnName();
                auto value = row[i];

                if(value.isNull()) {
                    rowMap[columnName] = "NULL"; 
                }
                else if(value.getType() == mysqlx::Value::Type::STRING) {
                    rowMap[columnName] = value.get<string>();
                }
                else if (value.getType() == mysqlx::Value::Type::INT64) {
                    rowMap[columnName] = to_string(value.get<int64_t>()); 
                }
                else if (value.getType() == mysqlx::Value::Type::UINT64) {
                    rowMap[columnName] = to_string(value.get<uint64_t>());
                }
                else {
                    rowMap[columnName] = "Unsupported Type"; 
                }
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
