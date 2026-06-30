cmake_minimum_required(VERSION 4.3.3)

project(MyRaylibProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(MyRaylibProject src/main.cpp)

find_package(raylib CONFIG REQUIRED)

target_link_libraries(MyRaylibProject PRIVATE raylib)