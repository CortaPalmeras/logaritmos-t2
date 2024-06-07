cmake_minimum_required(VERSION 3.20)

project(logs_tarea2
    DESCRIPTION "Tarea 3 de Diseño y Analisis de Algoritmos"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options( "-Wall" "-Wextra" "-Werror" "-Wpedantic" )

elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options( "/W4" "/WX" )

endif()

add_subdirectory(src)
add_subdirectory(test)
