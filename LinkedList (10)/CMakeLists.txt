cmake_minimum_required(VERSION 3.13)

project(LinkedList)

set(CMAKE_CXX_STANDARD 17)
file(GLOB_RECURSE SOURCES "./*.cpp" "./*.h")
include_directories("src/")

add_executable(Main ${SOURCES} Test.cpp)
