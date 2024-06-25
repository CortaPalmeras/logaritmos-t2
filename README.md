
## Tarea 2 Diseño y Análisis de Algoritmos

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

### Generar gráficos

En la raiz de la tarea se encuentra un script de python llamado `generar_graficos.py`
que genera los graficos del informe y los deja en una carpeta llamada `out`, los datos
los toma de un archivo llamado `dijkstra.csv` que tambien está en la raiz del proyecto
y contiene el set de datos utilizado para el informe.

Para ejecutar el script se deben instalar las dependencias y luego se puede correr 
directamente usando python:
```bash
pip install -r requirements.txt
python3 generar_graficos.py
```

Para que el script utilice el archivo `dijkstra.csv` generado localmente con el programa
`experimentacion` o `experimentacion.exe` el achivo se debe mover al directorio raiz del
proyecto.

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

