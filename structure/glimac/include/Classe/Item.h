//
// Created by Mathieu on 30/12/2017.
//
#include <glimac/glm.hpp>
#include <Classe/OGL3.hpp>


#ifndef IMACMAN_ITEM_H
#define IMACMAN_ITEM_H

enum Type{vide,Entity,Consummable,GUM,SGUM,FRUIT,Wall,Character,IMACMAN,Ghost,BLUE,PINK,RED,YELLOW};


class Item{
    
    protected:
        
        int orientation;//de 0 à 4, représente la direction de l'objet clockwise (0=face,1= profil gauche, 2=arrière,3=profil droit)
        
        Type type;// décrit sa fonction
        Modele* apparence;// information sur l'apparence de l'objet (par rapport à opengl)
        
        glm::mat4 Projection,Mod;
        glm::vec3 m_coordonnee;

        
        void calculModeleMatrix();


    public:
        Item(){}
        Item(Modele* modele,glm::vec3 pos);
        virtual ~Item(){}

        float hauteur,largeur;//DIMENSION du cube circonscrit, pour les collisions


        void setCoordonnee(glm::vec3 coord);

        Modele* getApparence();
        Type getType();
        glm::vec3 getCoordonnee();
        glm::mat4 getProjection();
        glm::mat4 getMod();

        virtual int collide(Item* item){

        }

        void update();
        int wFile(); //écrit dans un fichier
        virtual int dessin(glm::mat4 view); //dessine sur la fenetre
};


#endif //IMACMAN_ITEM_H

