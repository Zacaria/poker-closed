#ifndef _JOUEUR_HPP_
#define _JOUEUR_HPP_
#include <iostream>
#include <string>
#include <vector>

struct Joueur
{
    int id;
    std::string nom;
    void salutations() {
        std::cout << "Hey ! moi c'est " << nom << " : " << id << std::endl;
    };
};

typedef std::vector<Joueur *> Joueurs;

Joueurs initJoueurs(std::string nomJoueur);

#endif