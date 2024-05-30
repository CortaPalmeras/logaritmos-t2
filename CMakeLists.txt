cmake_minimum_required(VERSION 3.20)

project(logs_tarea2
    DESCRIPTION "Tarea 2 de Geometría Computacional"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

#add_compile_options(-Wall -Wextra -Werror -pedantic)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)
