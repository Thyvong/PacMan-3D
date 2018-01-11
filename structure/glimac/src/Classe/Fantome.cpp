//
// Created by Mathieu on 30/12/2017.
//

#include <Classe/Fantome.h>
#include <Classe/PacMan.h>

void Fantome::deplacement(int orient) {
    Personnage::deplacement(orient);
}

void Fantome::deplacement() {
    glm::vec3 move;
    int orient = orientation;
    srand(time(NULL));

    switch(orient){
        case 0:{
            move=glm::vec3(0,0,1.0f*m_vitesse);
        }break;
        case 1:{
            move=glm::vec3(-1.0f*m_vitesse,0,0);
        }break;
        case 2:{
            move=glm::vec3(0,0,-1.0f*m_vitesse);
        }break;
        case 3:{
            move=glm::vec3(1.0f*m_vitesse,0,0);
        }break;
        default:{
            std::cout<<"Deplacement chelou"<<std::endl;
        }break;
    }

    if(!wallcollide(orient, move)){
        do{

            orient = rand()%4;
        }while(orient == orientation);
    }
    deplacement(orient);




}

void FantomeBleu::deplacement(int orient) {
    Personnage::deplacement(orient);
}

void FantomeBleu::deplacement() {
    Fantome::deplacement();
}


void FantomeRouge::deplacement(int orient) {
    Personnage::deplacement(orient);
}

void FantomeRouge::deplacement() {
    Fantome::deplacement();
}

void FantomeRose::deplacement(int orient) {
    Personnage::deplacement(orient);
}

void FantomeRose::deplacement() {
    Fantome::deplacement();
}





void FantomeJaune::deplacement(int orient) {
    Personnage::deplacement(orient);
}
void FantomeJaune::deplacement() {
    Fantome::deplacement();
}
int Fantome::collide(PacMan* pac){

	if(etat!=Death){
		if (pac->getetat()==Super)
		{
			std::cout<<"MOI FANTOME J'AI MOURU"<<std::endl;
			etat=Death;
			return 0;
		}
		return 1;
	}
	return 0;
	
}
