cmake_minimum_required(VERSION 3.22.0)

project(Cube)

add_executable(${PROJECT_NAME} src/game.cpp src/cube.cpp src/main.cpp)

target_link_libraries(${PROJECT_NAME} SDL2)
