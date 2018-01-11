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
        int collide(){
            if (isActive())
            {  
                std::cout<<"MIAM"<<std::endl;
                active=false;
                return Bonus();
            }
            return 0;
        }
        bool isActive();
        int dessin(glm::mat4 view);
};
class Gomme : public Nourriture{

    public:
        Gomme(){}
        Gomme(Modele* modele,glm::vec3 pos):Nourriture(modele,pos){
        	type=GUM;
        }

        int Bonus(){
        	return 100;
        }
        //int wFile(); //écrit dans un fichier

};
class SuperGomme : public Nourriture {

    public:
        SuperGomme(){}
        SuperGomme(Modele* modele,glm::vec3 pos):Nourriture(modele,pos){
        	type=SGUM;
        }
        int Bonus(){
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
        	return 500;
        }
        //int wFile(); //écrit dans un fichier

};

#endif //IMACMAN_NOURRITURE_H
