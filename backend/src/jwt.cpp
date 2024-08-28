#include "jwt.h"
#include <jwt-cpp/jwt.h> 

using namespace std;

namespace {
    const string secret_key = "california";
}

string jwt::createToken(int userId) {
    auto token = jwt::create()
                    .set_issuer("let_us_cook")
                    .set_type("JWS")
                    .set_payload_claim("user_id", jwt::claim(to_string(userId)))
                    .sign(jwt::algorithm::hs256{secret_key});
    return token;
}

int jwt::getUserIdFromToken(const string &token) {
    auto decodedToken = jwt::decode(token);
    auto userId = decodedToken.get_payload_claim("user_id").as_string();
    return stoi(userId);
}

bool jwt::validateToken(const string &token) {
    try {
        auto verifier = jwt::verify()
                        .allow_algorithm(jwt::algorithm::hs256{secret_key})
                        .with_issuer("let_us_cook");
        verifier.verify(jwt::decode(token));
        return true;
    } 
    catch (const exception &e) {
        cerr << "JWT validation error: " << e.what() << endl;
        return false;
    }
}
