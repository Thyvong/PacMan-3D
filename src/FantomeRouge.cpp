//
// Created by Mathieu on 30/12/2017.
//

#include "../includes/FantomeRouge.h"

FantomeRouge::FantomeRouge(){
    m_id = 8;
    setCoordonnee(11,30,1);
}

Coordonnee FantomeRouge::deplacement(Coordonnee coordonnee) {
    return Coordonnee(0,0,0);
}

int FantomeRouge::collision(Item *item) {
    return 0;
}

int FantomeRouge::dessin() {
    return 0;
}

/*int FantomeRouge::wFile() {
    return 0;
}*/

