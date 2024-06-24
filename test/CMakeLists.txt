
add_executable(
    tests_funcionamiento
    tests_funcionamiento.cpp
)

target_link_libraries(
    tests_funcionamiento
    tarea
)

add_executable(
    experimentacion
    experimentacion.cpp
)

target_link_libraries(
    experimentacion
    tarea
)
