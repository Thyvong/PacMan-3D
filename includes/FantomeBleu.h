//
// Created by Mathieu on 30/12/2017.
//

#ifndef IMACMAN_FANTOMEBLEUE_H
#define IMACMAN_FANTOMEBLEUE_H


#include "Fantome.h"

class FantomeBleu : public Fantome {

    public:
        FantomeBleu();
        Coordonnee deplacement(Coordonnee coordonnee);
        int collision(Item *item); //Valeur de retour à voir (void ou int)
        int wFile(); //écrit dans un fichier
        int dessin(); //dessine sur la fenetre

};

#endif //IMACMAN_FANTOMEBLEUE_H
