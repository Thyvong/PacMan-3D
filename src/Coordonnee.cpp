//
// Created by Mathieu on 30/12/2017.
//

#include "../includes/Coordonnee.h"

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

/***************************************************************A faire********************************************************************************/
/*Coordonnee Coordonnee::translation() {
    return Coordonnee(0,0,0);
}

Coordonnee Coordonnee::rotation() {
    return Coordonnee(0,0,0);
}

Coordonnee Coordonnee::scale() {
    return Coordonnee(0,0,0);
}

/***************************************************************A faire********************************************************************************/

