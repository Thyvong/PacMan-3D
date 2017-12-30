//
// Created by Mathieu on 30/12/2017.
//

#include "Coordonnee.h"

#ifndef IMACMAN_ITEM_H
#define IMACMAN_ITEM_H

class Item{
    protected:
        int m_id;
        Coordonnee m_coordonnee;
        Item();

    public:
        int getId();
        Coordonnee getCoordonnee();
        virtual int wFile() = 0; //écrit dans un fichier
        virtual int dessin() = 0; //dessine sur la fenetre
};


#endif //IMACMAN_ITEM_H

