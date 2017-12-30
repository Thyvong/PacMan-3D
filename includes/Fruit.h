//
// Created by Mathieu on 30/12/2017.
//

#ifndef IMACMAN_FRUIT_H
#define IMACMAN_FRUIT_H

#include "Nourriture.h"

class Fruit : public Nourriture{

    public:
        Fruit();
        int Bonus();
        int wFile(); //écrit dans un fichier
        int dessin(); //dessine sur la fenetre
};
#endif //IMACMAN_FRUIT_H
