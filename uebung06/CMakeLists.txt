cmake_minimum_required(VERSION 3.1)
project(pixel LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -pedantic")

add_library(point point.cc)
add_library(canvas canvas.cc)

add_executable(pixel main.cc)

target_link_libraries(pixel point canvas)
