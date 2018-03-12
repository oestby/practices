cmake_minimum_required(VERSION 3.0.0)
project(practice_10)

add_compile_options(-g -Wall -std=c++17)

include_directories(include include/Graphics)
file(GLOB graphics_SRC "src/Graphics/*.cpp")
file(GLOB matrix_SRC "src/Matrix/*.cpp")

add_library(graphics_lib ${graphics_SRC})
add_library(matrix_lib ${matrix_SRC})

add_executable(main main.cpp)
target_link_libraries(main graphics_lib matrix_lib)
