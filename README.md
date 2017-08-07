# makefiles
This repo contains some makefile templates

## example1

With the help of GNU make built-in rules, this makefile can auto generate dependence file (*.d) and object files (*.o) under separate folder and same directory structure with source code.

In this example1:
  sources are: main.cpp & module/util.cpp
  obj & deps are all under bin, with the same folder structure as sources
  .
  ├── 8br6L.png
  ├── bin
  │   ├── cvshow
  │   └── obj
  │       ├── main.d
  │       ├── main.o
  │       └── module
  │           ├── util.d
  │           └── util.o
  ├── main.cpp
  ├── main.h
  ├── Makefile
  ├── module
  │   └── util.cpp
  └── version.h




