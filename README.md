
## Tarea 1 de Geometría Computacional

Para generar los comandos de compilación para distintas plataformas
utilziamos CMake, la tarea fue probada en Debian usando el compilador
g++ y en Windows usando MSVC.

#### Requisitos para compilar la tarea:

##### Linux:

- `cmake`
- `g++`
- `make` para ejecutar los comandos.

##### Windows:

- `cmake`
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
cmake ..
```
- Compilar con Make
```bash
make
```
- Ejecutar la tarea
```bash
./test  0
```


#### Layout de la tarea:

