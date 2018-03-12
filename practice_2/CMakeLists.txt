cmake_minimum_required(VERSION 2.8.3)
project(practice_2)

set(CMAKE_CPP_FLAGS "-g -std=c++17 -Wall")

include_directories(include)
file(GLOB SRC "src/*.cpp")

add_library(practice_lib ${SRC})

add_executable(main task_3.cpp)
target_link_libraries(main practice_lib)

