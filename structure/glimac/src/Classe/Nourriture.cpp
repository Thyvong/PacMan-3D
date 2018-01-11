//
// Created by Mathieu on 30/12/2017.
//


#include <Classe/Nourriture.h>


bool Nourriture::isActive(){
	return active;
}
int Nourriture::dessin(glm::mat4 view){
	if(isActive()){
		Item::dessin(view);
	}
}