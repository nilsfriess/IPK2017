cmake_minimum_required(VERSION 3.1)
project(statistics LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -pedantic")

add_executable(statistics io.hh io.cc statistics.hh main.cc)
