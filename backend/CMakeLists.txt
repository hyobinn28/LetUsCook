#CMake version required
cmake_minimum_required(VERSION 3.10)
project(LetUsCook)
set(CMAKE_CXX_STANDARD 17)

#find and include OpenSSL
find_package(OpenSSL REQUIRED)

#find MySQL client library
find_library(MYSQL_CLIENT mysqlcppconn8-static PATHS /Users/mac/final/final-project-template-let-us-cook/vcpkg/installed/arm64-osx/lib)

#directories for MySQL
include_directories(/Users/mac/final/final-project-template-let-us-cook/vcpkg/installed/arm64-osx/include)

#source files
add_executable(LetUsCook
    src/main.cpp
    src/Recipe.cpp
    src/RecipeManager.cpp
    src/UserManager.cpp
    src/jwt.cpp
    src/Database.cpp
    src/bcrypt.cpp
)

#OpenSSL, MySQL client, CoreFoundation, and resolver libraries
target_link_libraries(LetUsCook 
    OpenSSL::SSL 
    OpenSSL::Crypto 
    ${MYSQL_CLIENT}
    "-framework CoreFoundation"  #framework for macOS
    "-lresolv"                   #resolver library for macOS
)
