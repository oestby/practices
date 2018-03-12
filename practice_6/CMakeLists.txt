cmake_minimum_required(VERSION 3.0.0)
project(practice_6)

add_compile_options(-g -Wall -std=c++17)

include_directories(include)
file(GLOB SRC "src/*.cpp")

add_library(gameobject_lib ${SRC})

add_executable(main main.cpp)
target_link_libraries(main gameobject_lib -lsfml-graphics -lsfml-window -lsfml-system)
