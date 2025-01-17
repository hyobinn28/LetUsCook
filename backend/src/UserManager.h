#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <string>

using namespace std;

class UserManager {
public:
    bool registerUser(const string &username, const string &email, const string &password);
    string loginUser(const string &username, const string &password);

private:
    string hashPassword(const string &password);
    bool validatePassword(const string &password, const string &storedHash);
};

#endif