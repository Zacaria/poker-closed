#ifndef _JOUEUR_HPP_
#define _JOUEUR_HPP_
#include <string>
#include <vector>

struct Joueur
{
    int id;
    std::string nom;
};

typedef std::vector<Joueur *> Joueurs;

#endif