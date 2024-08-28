cmake_minimum_required(VERSION 3.10)
project(LetUsCook)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenSSL REQUIRED)
find_library(MYSQL_CLIENT mysqlcppconn PATHS /path/to/vcpkg/installed/arm64-osx/lib)

include_directories(/Users/mac/final/final-project-template-let-us-cook/vcpkg/installed/arm64-osx/include)

add_executable(LetUsCook
    src/main.cpp
    src/Recipe.cpp
    src/RecipeManager.cpp
    src/UserManager.cpp
    src/jwt.cpp
    src/Database.cpp
    src/bcrypt.cpp
)

target_link_libraries(LetUsCook OpenSSL::SSL OpenSSL::Crypto)
