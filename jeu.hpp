#ifndef _JEU_HPP_
#define _JEU_HPP_
#include "cartes.hpp"
#include "joueur.hpp"

void jouer(Cartes *cartes, Joueurs *joueurs);

struct TourJeu
{
    Joueurs joueurs;
    int mises;
    int miseIndiv;
    bool ouvert;
};

#endif