
# Añadir codigo fuente aquí,
# no puede haber un main.
add_library(
    tarea
    arbol_binomial.cpp
    dijkstra.cpp
    fibonacci.cpp
    heap.cpp
    tarea.cpp
)

target_include_directories(
    tarea
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

