#include "UserManager.h"
#include "Database.h"
#include "jwt.h"
#include "bcrypt.h"
#include <openssl/sha.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>
#include <string>
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

string UserManager::hashPassword(const string& password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password.c_str(), password.size());
    SHA256_Final(hash, &sha256);

    BIO *bio, *b64;
    BUF_MEM *bufferPtr;

    b64 = BIO_new(BIO_f_base64());
    bio = BIO_new(BIO_s_mem());
    bio = BIO_push(b64, bio);

    BIO_write(bio, hash, SHA256_DIGEST_LENGTH);
    BIO_flush(bio);
    BIO_get_mem_ptr(bio, &bufferPtr);

    string encodedData(bufferPtr->data, bufferPtr->length);
    BIO_free_all(bio);

    return encodedData;
}

bool UserManager::validatePassword(const string& password, const string& storedHash) {
    string hashedPassword = hashPassword(password); // Hash the input password
    return hashedPassword == storedHash;
}