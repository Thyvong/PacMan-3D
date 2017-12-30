//
// Created by Mathieu on 30/12/2017.
//

#ifndef IMACMAN_FANTOMEJAUNE_H
#define IMACMAN_FANTOMEJAUNE_H


#include "Fantome.h"

class FantomeJaune : public Fantome {

    public:
        FantomeJaune();
        Coordonnee deplacement(Coordonnee coordonnee);
        int collision(Item *item); //Valeur de retour à voir (void ou int)
        int wFile(); //écrit dans un fichier
        int dessin(); //dessine sur la fenetre

};
#endif //IMACMAN_FANTOMEJAUNE_H
