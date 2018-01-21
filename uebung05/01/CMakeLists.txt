cmake_minimum_required(VERSION 3.1)
project(checkparans LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -pedantic")

add_library(input input.cc)
add_library(lint lint.cc)

add_executable(checkparans main.cc)

target_link_libraries(checkparans input lint)

