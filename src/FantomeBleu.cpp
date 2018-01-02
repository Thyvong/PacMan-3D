//
// Created by Mathieu on 30/12/2017.
//

#include "../includes/FantomeBleu.h"


FantomeBleu::FantomeBleu() {
    m_id = 5;
    setCoordonnee(12,30,1);
}

Coordonnee FantomeBleu::deplacement(Coordonnee coordonnee) {
    return Coordonnee();
}

int FantomeBleu::collision(Item *item) {
    return 0;
}

/*int FantomeBleu::wFile() {
    return 0;
}*/

int FantomeBleu::dessin() {
    return 0;
}


