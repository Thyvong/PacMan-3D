//
// Created by Mathieu on 30/12/2017.
//

#ifndef IMACMAN_NOURRITURE_H
#define IMACMAN_NOURRITURE_H

#include "Item.h"
#include "OGL3.hpp"

class Nourriture : public Item{

    protected:
        Nourriture(){}
        Nourriture(Modele* modele,glm::vec3 pos):Item(modele,pos){
        	type=Consummable;
        	active=true;
        }
        bool active;


    public:
        virtual int Bonus() = 0;
};
class Gomme : public Nourriture{

    public:
        Gomme(){}
        Gomme(Modele* modele,glm::vec3 pos):Nourriture(modele,pos){
        	type=GUM;
        }
        int Bonus(){
        	active=false;
        	return 100;
        }
        //int wFile(); //écrit dans un fichier
        int dessin(); //dessine sur la fenetre
};
class SuperGomme : public Nourriture {

    public:
        SuperGomme(){}
        SuperGomme(Modele* modele,glm::vec3 pos):Nourriture(modele,pos){
        	type=SGUM;
        }
        int Bonus(){
        	active=false;
        	return 1000;
        }
};
class Fruit : public Nourriture{

    public:
        Fruit(){}
        Fruit(Modele* modele,glm::vec3 pos):Nourriture(modele,pos){
        	type=FRUIT;
        }
        int Bonus(){
        	active=false;
        	return 500;
        }
        //int wFile(); //écrit dans un fichier
        int dessin(); //dessine sur la fenetre
};

#endif //IMACMAN_NOURRITURE_H
