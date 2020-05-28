#include <string>
#include "joueur.hpp"

Joueurs initJoueurs(std::string nomJoueur) {
    Joueurs joueurs;
    Joueur *bob = new Joueur {
        .id = 1,
        .nom = nomJoueur,
    };

    joueurs.push_back(bob);
    return joueurs;
}