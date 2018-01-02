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
        void setCoordonnee( int x, int y, int z);

    public:
        int & getId();
        Coordonnee & getCoordonnee();
        int wFile(); //écrit dans un fichier
        virtual int dessin() = 0; //dessine sur la fenetre
};


#endif //IMACMAN_ITEM_H

