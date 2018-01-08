//
// Created by Mathieu on 30/12/2017.
//

#include <iostream>
#include <Classe/Nourriture.h>
#include <Classe/PacMan.h>


int PacMan::mange(Nourriture * nourriture) {
    return 0;
}

int PacMan::bonus(Nourriture * nourriture) {
    return 0;
}

/*int PacMan::wFile() {
    return 0;
}*/

int PacMan::dessin() {
    return 0 ;
}

// void PacMan::deplacement(glm::vec3 coordonnee) {
//     setCoordonnee(m_coordonnee+coordonnee);
// }

int PacMan::collision(Item * item) {
    return 0;
}

int PacMan::croisement(Gomme * gomme) {
    if (getCoordonnee() == gomme->getCoordonnee())
        return 10;
    return 0;
}

int PacMan::croisement(SuperGomme * supergomme) {
    if (getCoordonnee() == supergomme->getCoordonnee())
        return 1;
    return 0;
}

int PacMan::croisement(Fantome * fantome) {
    if (getCoordonnee() == fantome->getCoordonnee())
        return 1;
    return 0;
}

int PacMan::croisement(Fruit * fruit) {
    if (getCoordonnee() == fruit->getCoordonnee())
        return 500;
    return 0;
}










