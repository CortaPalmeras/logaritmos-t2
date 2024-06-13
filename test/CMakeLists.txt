
add_executable(
    tarea_test
    tarea_test.cpp
    cola_fibonacci_test.cpp
    heap_test.cpp
    dijkstra_test.cpp
)

# target_link_libraries(
#     tarea_test
#     tarea
# )

target_include_directories(
    tarea_test
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

