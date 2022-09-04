cmake_minimum_required(VERSION 3.10)
project(BrickBreaker VERSION 1.0)

add_subdirectory("${PROJECT_SOURCE_DIR}/libs/SDL")

add_executable(BrickBreaker "${PROJECT_SOURCE_DIR}/src/main.c")
include_directories("${PROJECT_SOURCE_DIR}/inc")

target_link_libraries(BrickBreaker SDL2 SDL2main)
