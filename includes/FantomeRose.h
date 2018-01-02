//
// Created by Mathieu on 30/12/2017.
//

#ifndef IMACMAN_FANTOMEROSE_H
#define IMACMAN_FANTOMEROSE_H


#include "Fantome.h"

class FantomeRose : public Fantome {

    public:
        FantomeRose();
        Coordonnee deplacement(Coordonnee coordonnee);
        int collision(Item *item); //Valeur de retour à voir (void ou int)
        //int wFile(); //écrit dans un fichier
        int dessin(); //dessine sur la fenetre
};

#endif //IMACMAN_FANTOMEROSE_H
