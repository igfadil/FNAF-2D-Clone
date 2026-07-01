cmake_minimum_required(VERSION 4.3.3)

project(MyRaylibProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(raylib CONFIG REQUIRED)

add_executable(MyRaylibProject
    src/main.cpp
    src/game/Game.cpp
    src/game/GameState.cpp
    src/states/Camera.cpp
    src/states/Menu.cpp
    src/states/Office.cpp
    src/states/GameOver.cpp
)

target_include_directories(MyRaylibProject PRIVATE src)

target_link_libraries(MyRaylibProject PRIVATE raylib)