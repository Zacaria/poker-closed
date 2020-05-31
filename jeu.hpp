#ifndef _JEU_HPP_
#define _JEU_HPP_
#include "cartes.hpp"
#include "joueur.hpp"
// paquet de carte
// joueurs

void jouer(Paquet *cartes, Joueurs *joueurs, bool debug);

enum action
{
    coucher,
    suivre,
    relancer,
    tapis,
};

#endif