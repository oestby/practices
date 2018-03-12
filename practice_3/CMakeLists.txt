cmake_minimum_required(VERSION 3.0.0)
project(practice_3)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++17")
file(GLOB SRC "src/*.cpp")
include_directories(include)

add_library(cannon_lib ${SRC})

add_executable(main main.cpp)
target_link_libraries(main cannon_lib)
