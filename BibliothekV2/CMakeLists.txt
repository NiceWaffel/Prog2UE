cmake_minimum_required(VERSION 3.13)

project(LottiKarotti)

set(CMAKE_CXX_STANDARD 17)
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h")
include_directories("src/")

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(OPENSSL_ROOT_DIR /usr/lib/x86_64-linux-gnu/)
find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})

add_executable(Main ${SOURCES} src/Main.cpp)

target_link_libraries(Main ${CURSES_LIBRARIES} ${OPENSSL_LIBRARIES})

