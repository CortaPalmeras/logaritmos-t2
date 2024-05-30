
add_library(
    prueba_lib
    prueba_lib.cpp
)

target_include_directories(
    prueba_lib
    INTERFACE ${PROJECT_SOURCE_DIR}/include
)
