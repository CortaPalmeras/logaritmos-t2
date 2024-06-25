
## Tarea 1 de Geometría Computacional

Para generar los comandos de compilación para distintas plataformas
utilziamos CMake, la tarea fue probada en Debian usando el compilador
g++ y en Windows usando MSVC.

### Requisitos para compilar la tarea:

#### Linux:

- CMake
- g++, tambien sirve clang++
- GNU Make

#### Windows:

- CMake
- Visual Studio (el IDE) o Visual Studio Build Tools

### Instrucciones de ejecución:

#### Linux:

- Crear un directorio llamado "build"
```bash
mkdir build
cd build
```

- Crear el cache de CMake
```bash
cmake -D CMAKE_BUILD_TYPE=Release ..
```

- Compilar con Make
```bash
make
```

- Ejecutar la tarea
```bash
./test/experimentacion
```

- Tambien habrá un archivo llamado `tests_funcionamiento` que contine los tests
no relacionados con la experimentacion, estos utilizan el macro `assert` por lo que
no sirven con opciones de optimizacion, si se desea ejecutar estos tests se tiene
que recompilar:
```bash
cmake -D CMAKE_BUILD_TYPE=Debug ..
make
./test/tests_funcionamiento
```

#### Windows

Es necesario utilizar "Developer PowerShell for VS" para que CMake pueda
encontrar el compilador automaticamente.

- Crear un directorio llamado build
```powershell
mkdir build
cd build
```

- Crear el cache de CMake y compilar
```powershell
cmake ..
cmake --build . --config Release
```

- Ejecutar la tarea
```powershell
.\test\Release\experimentacion.exe
```

- Tambien habrá un archivo llamado `tests_funcionamiento.exe` que contine los tests
no relacionados con la experimentacion, estos utilizan el macro `assert`, por lo que
no sirven con opciones de optimizacion, si se desea ejecutar estos tests se tiene
que recompilar:
```powershell
cmake --build . --config Debug
.\test\Debug\tests_funcionamiento.exe
```

### Layout de la tarea:

```
.
├── CMakeLists.txt
├── crear_grafico.py
├── dijkstra.csv
├── README.md
├── include                 // Headers de la tarea
│   ├── cola_fibonacci.hpp
│   ├── dijkstra.hpp
│   └── heap.hpp
├── src                     // Implementaciones de las colas y el algoritmo
│   ├── CMakeLists.txt
│   ├── cola_fibonacci.cpp
│   ├── dijkstra.cpp
│   └── heap.cpp
└── test                    // Tests y experimentacion
    ├── CMakeLists.txt
    ├── experimentacion.cpp
    └── tests_funcionamiento.cpp
```

