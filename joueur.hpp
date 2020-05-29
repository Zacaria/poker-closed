#ifndef _JOUEUR_HPP_
#define _JOUEUR_HPP_
#include <iostream>
#include <string>
#include <vector>
#include "cartes.hpp"

struct Joueur
{
    int id;
    std::string nom;
    int jetons;
    Main main;
    void salutations() {
        std::cout << "Hey ! moi c'est " << nom << ", mon id : " << id << std::endl;
    };
};

typedef std::vector<Joueur *> Joueurs;

Joueurs initJoueurs(std::string nomJoueur, int nombreIA, int jetonsDepart);
void clearJoueurs(Joueurs *joueurs);

#endif