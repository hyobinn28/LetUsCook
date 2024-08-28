#ifndef DATABASE_H
#define DATABASE_H

#include <mysqlx/xdevapi.h> // Include the MySQL X DevAPI header
#include <string>
#include <vector>
#include <map>

using namespace std;

class Database {
public:
    Database(); 
    ~Database(); 
    
    bool execute(const string& query);
    vector<map<string, string>> query(const string& query); 
    int getLastInsertId(); 

private:
    mysqlx::Session* session; 
    mysqlx::Schema* schema;   
};

#endif
