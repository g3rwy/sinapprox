cmake_minimum_required(VERSION 3.25)
project(sinapprox C)

set(CMAKE_C_STANDARD 23)
link_libraries(m)
option(RAYLIB "Set to compile a gui app" OFF)

if(RAYLIB)
    link_libraries(raylib)
    add_compile_definitions(USE_RAYLIB)
endif()
add_executable(sinapprox main.c )
