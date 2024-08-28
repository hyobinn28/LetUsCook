#include "UserManager.h"
#include "Database.h"
#include "jwt.h"
#include "bcrypt.h"  // Include the header file
#include <iostream>

using namespace std;

bool UserManager::registerUser(const string& username, const string& email, const string& password) {
    Database db;
    string hashedPassword = hashPassword(password);
    string query = "INSERT INTO users (username, email, passwordHash) VALUES ('" + username + "', '" + email + "', '" + hashedPassword + "');";
    return db.execute(query);
}

string UserManager::loginUser(const string& username, const string& password) {
    Database db;
    string query = "SELECT id, passwordHash FROM users WHERE username = '" + username + "';";
    auto result = db.query(query);

    if (result.size() == 1) {
        int userId = stoi(result[0]["id"]);
        string storedHash = result[0]["passwordHash"];
        if (validatePassword(password, storedHash)) {
            return jwt::createToken(userId);
        }
    }
    throw runtime_error("Invalid username or password.");
}

int UserManager::getUserIdFromToken(const string& token) {
    return jwt::getUserIdFromToken(token);
}

string UserManager::hashPassword(const string& password) {
    return generateHash(password);
}

bool UserManager::validatePassword(const string& password, const string& hash) {
    return generateHash(password) == hash;
}
