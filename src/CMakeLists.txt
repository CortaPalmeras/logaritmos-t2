
add_library(
    tarea STATIC
    dijkstra.cpp
    cola_fibonacci.cpp
)

target_include_directories(
    tarea
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

