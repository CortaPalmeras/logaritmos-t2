
# Añadir archivos de tests aquí
# solo puede haber un main
add_executable(
    tarea_test
    tarea_test.cpp
    cola_fibonacci_test.cpp
    heap_test.cpp
)

target_link_libraries(
    tarea_test
    tarea
)

