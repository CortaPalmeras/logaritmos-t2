
## Tarea 1 de Geometría Computacional

Para generar los comandos de compilación para distintas plataformas
utilziamos CMake, la tarea fue probada en Debian usando el compilador
g++ y en Windows usando MSVC.

#### Requisitos para compilar la tarea:

##### Linux:

- CMake
- g++, tambien sirve clang++
- GNU Make

##### Windows:

- CMake
- Visual Studio (el IDE) o Visual Studio Build Tools

#### Instrucciones de ejecución:

##### Linux:

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
./test 
```


#### Layout de la tarea:

