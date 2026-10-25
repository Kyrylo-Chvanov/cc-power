# Práctica 3

En esta práctica se implementó un programa que calcule la
función potencia(x , y) como una función primitiva recursiva de números naturales.

## Compilación

Para compilar dicho proyecto se necesita tener instalada la herramienta `cmake` y
un compilador de C++20.

El comando de compilación en entorno Linux es:
```
cmake -B build -S .
cd build
make
```

Se obtendrá un archivo ejecutable estático.

## Uso

El format de uso es:
```
$ power -x 2 -y 3
8
```
