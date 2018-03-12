cmake_minimum_required(VERSION 3.0.0)
project(practice_8)

add_compile_options(-g -Wall -std=c++17)

include_directories(include)

add_library(filestream_lib src/filestreams.cpp)
add_library(catalog_lib src/coursecatalog.cpp)

add_executable(main main.cpp)
target_link_libraries(main filestream_lib catalog_lib)
