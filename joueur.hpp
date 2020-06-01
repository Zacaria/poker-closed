#ifndef _JOUEUR_HPP_
#define _JOUEUR_HPP_
#include <iostream>
#include <string>
#include <vector>
#include "cartes.hpp"
#include "croupier.hpp"
#include "action.hpp"

struct Joueur
{
    int id;
    std::string nom;
    int jetons;
    Main main;
    bool isIA;
    void salutations();
    void montrerMain();
    bool miser(int nbJetons);
    bool parlerFermer();
    action parlerOuvert(const int miseIndiv);
    int demanderEchange();
};

typedef std::vector<Joueur *> Joueurs;

Joueurs initJoueurs(std::string nomJoueur);
void clearJoueurs(Joueurs *joueurs);

#endif