//
// Created by Mathieu on 30/12/2017.
//

#ifndef IMACMAN_COORDONNEES_H
#define IMACMAN_COORDONNEES_H

class Coordonnee{
private:
    float m_x;
    float m_y;
    float m_z;

public:
    Coordonnee(float x, float y, float z);
    Coordonnee();
    float getX();
    float getY();
    float getZ();

    Coordonnee translation();
    Coordonnee rotation();
    Coordonnee scale();

};

#endif //IMACMAN_COORDONNEES_H


