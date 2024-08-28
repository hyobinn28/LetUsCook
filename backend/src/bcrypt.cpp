#include <openssl/evp.h>
#include <openssl/sha.h>
#include <string>

using namespace std;

string generateHash(const string& password) {
    string salt = "somesalt";  
    unsigned char hash[SHA256_DIGEST_LENGTH];
    string saltedPassword = password + salt;
    SHA256((unsigned char*)saltedPassword.c_str(), saltedPassword.size(), hash);
    return string((char*)hash, SHA256_DIGEST_LENGTH);
}

bool validatePassword(const string& password, const string& hash) {
    string newHash = generateHash(password);  
    return newHash == hash;
}
