//
// Created by Mathieu on 30/12/2017.
//

#include "Coordonnee.h"
#include "Item.h"

#ifndef IMACMAN_PERSONNAGE_H
#define IMACMAN_PERSONNAGE_H

class Personnage : public Item{
    protected:
        int m_vitesse;
        Personnage();

    public:
        int getVitesse();
        virtual Coordonnee deplacement(Coordonnee coordonnee) = 0;
        virtual int collision(Item *item) = 0; //Valeur de retour à voir (void ou int)

};

#endif //IMACMAN_PERSONNAGE_H


