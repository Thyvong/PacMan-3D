//
// Created by Mathieu on 30/12/2017.
//

#ifndef IMACMAN_FANTOME_H
#define IMACMAN_FANTOME_H

#include <cstdlib>
#include "Personnage.h"


class PacMan;

class Fantome : public Personnage{
    public:
    	int collide(PacMan* pac);
    	void deplacement(int orient);
        void deplacement();
        
    protected:
        Fantome(){}
        Fantome(Modele* modele,glm::vec3 pos):Personnage(modele,pos){
        	type=Ghost;
        }
};
class FantomeBleu : public Fantome {

    public:
        FantomeBleu(){}
        FantomeBleu(Modele* modele,glm::vec3 pos):Fantome(modele,pos){
        	type=BLUE;
            m_vitesse=0.020f;

        }
        void deplacement(int orient);
        void deplacement();


};
class FantomeJaune : public Fantome {

    public:
        FantomeJaune(){}
        FantomeJaune(Modele* modele,glm::vec3 pos):Fantome(modele,pos){
            type = YELLOW;
            m_vitesse=0.020;

        }
        void deplacement(int orient);
        void deplacement();

};
class FantomeRose : public Fantome {

    public:
        FantomeRose(){}
        FantomeRose(Modele* modele,glm::vec3 pos):Fantome(modele,pos){
            type = PINK;
            m_vitesse=0.025f;

        }
        void deplacement(int orient);
        void deplacement();
};
class FantomeRouge : public Fantome {

    public:
        FantomeRouge(){}
        FantomeRouge(Modele* modele,glm::vec3 pos):Fantome(modele,pos){
            type = RED;
            m_vitesse=0.035f;

        }
        void deplacement(int orient);
        void deplacement();


};
#endif //IMACMAN_FANTOME_H
