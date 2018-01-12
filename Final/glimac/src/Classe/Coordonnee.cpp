//
// Created by Mathieu on 30/12/2017.
//

#include <Classe/Coordonnee.h>

Coordonnee::Coordonnee(float x, float y, float z) {
    m_x = x;
    m_y = y;
    m_z = z;
}

float Coordonnee::getX() {
    return m_x;
}

float Coordonnee::getY() {
    return m_y;
}

float Coordonnee::getZ() {
    return m_z;
}

Coordonnee::Coordonnee() {
    m_x = 0;
    m_y = 0;
    m_z = 0;
}

bool Coordonnee::operator==(Coordonnee coordonnee) {

    if(m_x == coordonnee.getX() && m_y == coordonnee.getY() && m_z == coordonnee.getZ())
        return true;

    return false;
}
