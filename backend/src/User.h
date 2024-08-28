#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User {
public:
    int id;
    string username;
    string email;
    string passwordHash;
};

#endif
