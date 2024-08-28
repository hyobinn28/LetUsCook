#ifndef JWT_H
#define JWT_H

#include <string>

using namespace std;

namespace jwt {
    string createToken(int userId); 
    int getUserIdFromToken(const string& token);
    bool validateToken(const string& token); 

}
#endif
