cmake_minimum_required(VERSION 3.0.0)
project (practice_11)

add_compile_options(-g -Wall -std=c++17)

include_directories(include)
add_library(person_lib "src/person.cpp")
add_library(utils_lib "src/functions.cpp")
add_library(tests_lib "src/tests.cpp")

target_link_libraries(utils_lib person_lib)
target_link_libraries(tests_lib person_lib utils_lib)

add_executable(main main.cpp)
target_link_libraries(main tests_lib) 
