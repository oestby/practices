cmake_minimum_required(VERSION 3.0.0)
project(practice_5)

add_compile_options(-g -Wall -std=c++17)

file(GLOB SRC "src/*.cpp")
include_directories(include)

add_library(blackjack_lib ${SRC})

add_executable(main main.cpp)
target_link_libraries(main blackjack_lib)
