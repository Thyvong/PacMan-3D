//
// Created by Mathieu on 30/12/2017.
//


#include "Item.h"
#include "Mur.hpp"
//#include "Terrain.h"

#include <glimac/glm.hpp>

#ifndef IMACMAN_PERSONNAGE_H
#define IMACMAN_PERSONNAGE_H

class Terrain;

class Personnage : public Item{
    protected:
        float m_vitesse;
        Personnage(){}
        Personnage(Modele* modele,glm::vec3 pos):Item(modele,pos){
        	type=Character;
        	m_vitesse=0.1f;
        }
        bool wallcollide(int orient,glm::vec3 move);
    public:
        float getVitesse();
        void changedirection(int orient);

        void deplacement(int orient);
        virtual int collision(Item *item); //Valeur de retour à voir (void ou int)

};

#endif //IMACMAN_PERSONNAGE_H


