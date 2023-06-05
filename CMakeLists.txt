cmake_minimum_required(VERSION 3.25)
project(sinapprox C)

set(CMAKE_C_STANDARD 23)
link_libraries(m)
add_executable(sinapprox main.c )
