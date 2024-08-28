#ifndef BCRYPT_H
#define BCRYPT_H

#include <string>

using namespace std;

string generateHash(const string &password);
bool validatePassword(const string &password, const string &hash);

#endif 