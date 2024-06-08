
# Añadir codigo fuente aquí,
# no puede haber un main.
add_library(
    tarea
    tarea.cpp
    heap.cpp
    cola_fibonacci.cpp
    cola_fibonacci_nodo.cpp
    dijkstra.cpp
)

target_include_directories(
    tarea
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

