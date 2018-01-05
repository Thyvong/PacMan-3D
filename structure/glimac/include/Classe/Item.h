//
// Created by Mathieu on 30/12/2017.
//
#include <glimac/glm.hpp>
#include <Classe/OGL3.hpp>

#ifndef IMACMAN_ITEM_H
#define IMACMAN_ITEM_H

enum Type{Entity,Consummable,GUM,SGUM,FRUIT,Wall,Character,IMACMAN,Ghost,BLUE,PINK,RED,YELLOW};


class Item{
    
    protected:
        Item(){}
        Item(Modele* modele,glm::vec3 pos);

        int orientation;//de 0 à 4, représente la direction de l'objet
        float hauteur,largeur;//DIMENSION du cube circonscrit, pour les collisions

        Type type;// décrit sa fonction
        Modele* apparence;// information sur l'apparence de l'objet (par rapport à opengl)
        
        glm::mat4 Projection,Mod;
        glm::vec3 m_coordonnee;

        
        void calculModeleMatrix();

    public:

        void setCoordonnee(glm::vec3 coord);

        Modele* getApparence();
        glm::vec3 getCoordonnee();
        glm::mat4 getProjection();
        glm::mat4 getMod();

        void update();
        int wFile(); //écrit dans un fichier
        virtual int dessin(); //dessine sur la fenetre
};


#endif //IMACMAN_ITEM_H

