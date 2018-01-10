//
// Created by Mathieu on 30/12/2017.
//

#include <Classe/Fantome.h>
#include <Classe/PacMan.h>

void Fantome::deplacement(int orient) {
    Personnage::deplacement(orient);
}
void FantomeBleu::deplacement(int orient) {
    Personnage::deplacement(orient);
}
void FantomeRouge::deplacement(int orient) {
    Personnage::deplacement(orient);
}
void FantomeRose::deplacement(int orient) {
    Personnage::deplacement(orient);
}
void FantomeJaune::deplacement(int orient) {
    Personnage::deplacement(orient);
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