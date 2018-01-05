//
// Created by Mathieu on 30/12/2017.
//


#include "Item.h"
#include "Mur.hpp"
#include <glimac/glm.hpp>

#ifndef IMACMAN_PERSONNAGE_H
#define IMACMAN_PERSONNAGE_H

class Personnage : public Item{
    protected:
        float m_vitesse;
        Personnage(){}
        Personnage(Modele* modele,glm::vec3 pos):Item(modele,pos){
        	type=Character;
        	m_vitesse=0.1f;
        }

    public:
        float getVitesse();

        virtual void deplacement(glm::vec3 coordonnee);
        virtual int collision(Item *item); //Valeur de retour à voir (void ou int)

};

#endif //IMACMAN_PERSONNAGE_H


