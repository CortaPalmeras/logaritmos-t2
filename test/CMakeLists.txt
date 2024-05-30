
# Añadir archivos de tests aquí
# solo puede haber un main
add_executable(
    tarea_test
    test_heap.cpp
)

target_link_libraries(
    tarea_test
    tarea
)
