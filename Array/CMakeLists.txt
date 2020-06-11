cmake_minimum_required(VERSION 3.13)

project(LottiKarotti)

set(CMAKE_CXX_STANDARD 17)
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h")
find_package(Curses REQUIRED)
include_directories("src/")
include_directories(${CURSES_INCLUDE_DIR})

add_executable(Main ${SOURCES} src/main.cpp)
target_link_libraries(Main ${CURSES_LIBRARIES})
