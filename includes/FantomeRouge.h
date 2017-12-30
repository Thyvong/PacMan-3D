//
// Created by Mathieu on 30/12/2017.
//

#ifndef IMACMAN_FANTOMEROUGE_H
#define IMACMAN_FANTOMEROUGE_H

#include "Fantome.h"

class FantomeRouge : public Fantome {

    public:
        FantomeRouge();
        Coordonnee deplacement(Coordonnee coordonnee);
        int collision(Item *item); //Valeur de retour à voir (void ou int)
        int wFile(); //écrit dans un fichier
        int dessin(); //dessine sur la fenetre

};
#endif //IMACMAN_FANTOMEROUGE_H
