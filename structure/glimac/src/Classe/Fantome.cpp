//
// Created by Mathieu on 30/12/2017.
//

#include <Classe/Fantome.h>

void Fantome::deplacement(glm::vec3 coordonnee) {
    setCoordonnee(m_coordonnee+coordonnee);
}
void FantomeBleu::deplacement(glm::vec3 coordonnee) {
    setCoordonnee(m_coordonnee+coordonnee);
}
void FantomeRouge::deplacement(glm::vec3 coordonnee) {
    setCoordonnee(m_coordonnee+coordonnee);
}
void FantomeRose::deplacement(glm::vec3 coordonnee) {
    setCoordonnee(m_coordonnee+coordonnee);
}
void FantomeJaune::deplacement(glm::vec3 coordonnee) {
    setCoordonnee(m_coordonnee+coordonnee);
}
int Fantome::collision(Item* item){
	return 0;
}
