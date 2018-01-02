//
// Created by Mathieu on 30/12/2017.
//

#ifndef IMACMAN_GOMME_H
#define IMACMAN_GOMME_H

#include "Nourriture.h"

class Gomme : public Nourriture{

    public:
        Gomme();
        int Bonus();
        //int wFile(); //écrit dans un fichier
        int dessin(); //dessine sur la fenetre
};

#endif //IMACMAN_GOMME_H
