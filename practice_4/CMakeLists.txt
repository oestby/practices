cmake_minimum_required(VERSION 3.0.0)
project(practice_4)

add_compile_options(-std=c++17 -g -Wall)
set(CMAKE_CPP_VERSION 17)

include_directories(include)
file(GLOB SRC "src/*.cpp")

add_library(mastermind_lib ${SRC})

add_executable(main main.cpp)
target_link_libraries(main mastermind_lib)
