cmake_minimum_required(VERSION 3.13)

project(LottiKarotti)

set(CMAKE_CXX_STANDARD 17)
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h")
include_directories("src/")

add_executable(Lotti ${SOURCES} src/main.cpp)
