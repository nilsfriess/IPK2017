cmake_minimum_required(VERSION 3.1)
project(date LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -pedantic")

add_library(date date.cc)

add_executable(date-test main.cc)

target_link_libraries(date-test date)
