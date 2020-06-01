#include <string>
#include <array>
#include <random>
#include "joueur.hpp"
#include "utils.hpp"
#include "constants.hpp"

std::array<std::string, 8> noms = {
    "Yahya", "Anna", "Laila", "Idir", "Hamadi", "Gael", "Foued", "Marie"};

Joueurs initJoueurs(std::string nomJoueur)
{
    Joueurs joueurs;
    for (int i = 0; i < constants::JOUEURS_IA; i++)
    {
        std::string nomJoueur = noms[i % noms.size()] + "_"; // modulo pour être sur de ne jamais sortir du tableau
        nomJoueur += i + 'O';                                 // on ajoute un caractère la fin du prénom pour que le nom soit unique
        Joueur *joueurIA = new Joueur{
            .id = i,
            .nom = nomJoueur,
            .jetons = constants::JETONS_DEPART,
            .isIA = true,
        };
        joueurIA->main.reserve(5);
        joueurs.push_back(joueurIA);

        joueurIA->salutations();
    }

    Joueur *joueurReel = new Joueur{
        .id = constants::JOUEURS_IA,
        .nom = nomJoueur,
        .jetons = constants::JETONS_DEPART,
        .isIA = false,
    };
    joueurReel->main.reserve(5);
    joueurs.push_back(joueurReel);

    shuffle(joueurs.begin(), joueurs.end(), std::default_random_engine(getRandomSeed()));

    return joueurs;
}

void clearJoueurs(Joueurs *joueurs)
{
    for (auto joueur : *joueurs)
    {
        delete joueur;
    }
    clearVector(joueurs);
}