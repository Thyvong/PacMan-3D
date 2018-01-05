//
// Created by Mathieu on 30/12/2017.
//

#include <Classe/Personnage.h>

/*int Personnage::getVitesse() {
    return vitesse;
}*/

float Personnage::getVitesse() {
    return m_vitesse;
}
void Personnage::deplacement(glm::vec3 coordonnee) {
    setCoordonnee(m_coordonnee+coordonnee);
}
int Personnage::collision(Item* item){
	return 0;
}
