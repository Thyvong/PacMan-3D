//
// Created by Mathieu on 30/12/2017.
//


#include "../includes/Coordonnee.h"
#include "../includes/FantomeRose.h"

FantomeRose::FantomeRose(){
    m_id = 7;
    setCoordonnee(14,30,1);
}

Coordonnee FantomeRose::deplacement(Coordonnee coordonnee) {
    return Coordonnee();
}

int FantomeRose::collision(Item *item) {
    return 0;
}

int FantomeRose::dessin() {
    return 0;
}

/*int FantomeRose::wFile() {
    return 0;
}*/

