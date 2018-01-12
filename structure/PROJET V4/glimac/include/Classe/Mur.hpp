#ifndef OBJET_H
#define OBJET_H

#include <glimac/SDLWindowManager.hpp>
#include <glimac/glm.hpp>
#include <GL/glew.h>
#include <iostream>

#include "OGL3.hpp"




class Mur : public Item
{
public:
	Mur(){}
	Mur(Modele* modele,glm::vec3 pos):Item(modele,pos){
		type=Wall;

	}

	
};






#endif