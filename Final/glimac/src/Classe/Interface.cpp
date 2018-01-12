//
// Created by Mathieu on 30/12/2017.
//

#include <Classe/Interface.h>
#include <Classe/PacMan.h>
#include <fstream>
#include <iostream>

Interface::Interface() {
    m_vies = 3;
    m_score = 0;
}

int Interface::jouer() {
    int choice = 0;
    std::cout << "Do you want to play ? \n Press 1 to play or 2 to quit\n";
    std::cin >> choice;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return choice;
}

int Interface::getVies() {
    return m_vies;
}

int Interface::getScore() {
    return m_score;
}

int Interface::wFile() {
    return 0;
}

int Interface::rFile() {
    return 0;
}

int Interface::pause() {
    return 0;
}

int Interface::recommencer() {
    return 0;
}

int Interface::continuer() {
    return 0;
}

int Interface::quitter() {
    return 0;
}