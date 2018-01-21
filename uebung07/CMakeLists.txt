cmake_minimum_required(VERSION 3.1)
project(pixel LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -pedantic")

add_library(sanitizer sanitizeword.cc)

add_executable(words word.hh main.cc)

target_link_libraries(words sanitizer)

