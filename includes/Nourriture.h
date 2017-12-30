//
// Created by Mathieu on 30/12/2017.
//

#ifndef IMACMAN_NOURRITURE_H
#define IMACMAN_NOURRITURE_H

#include "Item.h"

class Nourriture : public Item{

    protected:
        Nourriture();

    public:
        virtual int Bonus() = 0;
};

#endif //IMACMAN_NOURRITURE_H
