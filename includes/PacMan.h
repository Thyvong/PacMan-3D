//
// Created by Mathieu on 30/12/2017.
//

#ifndef IMACMAN_PAC_MAN_H
#define IMACMAN_PAC_MAN_H

#include "Nourriture.h"
#include "Personnage.h"

class PacMan : public Personnage{

    public:
        PacMan();
        int mange(Nourriture * nourriture );//valeur retour a voir
        int bonus(Nourriture * nourriture);//valeur retour a voir
        int wFile(); //écrit dans un fichier
        int dessin(); //dessine sur la fenetre
        Coordonnee deplacement(Coordonnee coordonnee);
        int collision(Item * item); //Valeur de retour à voir (void ou int)

};
#endif //IMACMAN_PAC_MAN_H
