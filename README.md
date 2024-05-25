
## Tarea 1 de Geometría Computacional

#### Requisitos para compilar y ejecutar la tarea:

- Un compilador de C++, puede ser `g++` o `clang++`.
- `make` para ejecutar los comandos.
- Alguna distribución de Linux, la tarea fue probada en Debian.

#### Instrucciones de ejecución:

Para ejecutar la tarea solo es necesario ejecutar `make` en el directorio raiz
de la tarea, por defecto la compilación se debería realizar con g++, sobreescribir
este comportamiento se puede la opción `CXX` en el comando, por ejemplo: `make CXX=clang++`
va a hacer que se compile con `clang++`, es necesario que el compilador que se 
utilice acepte las mismas flags especificadas en el archivo makefile.

También se puede compilar y ejecutar un test expecifico con 
los comandos: `make sexton_swinbank`, `make minmax`,
`make ciaccia_patella` y `make busqueda`.

#### Layout de la tarea:

```
.
├── bin
├── compile_flags.txt
├── docs
│   └── Tarea_2_DiseA_o_y_AnA_lisis_de_Algoritmos.pdf
├── include
│   └── heap.hpp
├── makefile
├── README.md
├── src
│   └── heap.cpp
└── test
    └── test_heap.cpp
```
