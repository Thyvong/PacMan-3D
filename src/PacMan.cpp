//
// Created by Mathieu on 30/12/2017.
//

#include <iostream>
#include "../includes/Nourriture.h"
#include "../includes/PacMan.h"


PacMan::PacMan() {}

int PacMan::mange(Nourriture * nourriture) {
    return 0;
}

int PacMan::bonus(Nourriture * nourriture) {
    return 0;
}

int PacMan::wFile() {
    return 0;
}

int PacMan::dessin() {
    return 0 ;
}

Coordonnee PacMan::deplacement(Coordonnee coordonnee) {
    return Coordonnee(0, 0, 0);
}

int PacMan::collision(Item * item) {
    return 0;
}




