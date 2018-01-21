cmake_minimum_required(VERSION 3.1)
project(pixel LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -pedantic -lSDL2")

add_library(pgm pgm.cc)
add_library(mb mandelbrot.cc)

add_executable(mandelbrot point.hh canvas.hh main.cc)

target_link_libraries(mandelbrot pgm mb)