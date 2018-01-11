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
			m_vitesse=0.0009f;

        }
        void deplacement(int orient);
        //int wFile(); //écrit dans un fichier
        void deplacement();



};
class FantomeJaune : public Fantome {

    public:
        FantomeJaune(){}
        FantomeJaune(Modele* modele,glm::vec3 pos):Fantome(modele,pos){
        	type = YELLOW;
			m_vitesse=0.00025f;

        }
        void deplacement(int orient);
        void deplacement();

    //int wFile(); //écrit dans un fichier

};
class FantomeRose : public Fantome {

    public:
        FantomeRose(){}
        FantomeRose(Modele* modele,glm::vec3 pos):Fantome(modele,pos){
        	type = PINK;
			m_vitesse=0.0055f;

        }
        void deplacement(int orient);
        void deplacement();

    //int wFile(); //écrit dans un fichier

};
class FantomeRouge : public Fantome {

    public:
        FantomeRouge(){}
        FantomeRouge(Modele* modele,glm::vec3 pos):Fantome(modele,pos){
        	type = RED;
			m_vitesse=0.025f;

        }
        void deplacement(int orient);

		void deplacement();

    //int wFile(); //écrit dans un fichier


};
#endif //IMACMAN_FANTOME_H
