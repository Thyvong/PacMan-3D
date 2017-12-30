cmake_minimum_required(VERSION 3.9)
project(ImacMan)

set(CMAKE_CXX_STANDARD 11)

add_executable(ImacMan main.cpp
        includes/Coordonnee.h src/Coordonnee.cpp
        includes/Item.h src/Item.cpp
        includes/Personnage.h src/Personnage.cpp
        includes/Nourriture.h src/Nourriture.cpp
        includes/PacMan.h src/PacMan.cpp
        includes/Gomme.h src/Gomme.cpp
        src/SuperGomme.cpp includes/SuperGomme.h
        includes/Fruit.h src/Fruit.cpp
        includes/Fantome.h
        includes/FantomeRouge.h src/FantomeRouge.cpp
        includes/FantomeRose.h
        src/FantomeBleu.cpp includes/FantomeBleu.h
        includes/FantomeJaune.h src/FantomeJaune.cpp src/FantomeRose.cpp src/Fantome.cpp includes/Terrain.h src/Terrain.cpp includes/Interface.h src/Interface.cpp)