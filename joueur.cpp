#include <string>
#include <array>
#include <random>
#include "joueur.hpp"
#include "utils.hpp"

std::array<std::string, 8> noms = {
    "Yahya", "Anissa", "Laila", "Rayan", "Michel", "Nicolas", "Foued", "Marie"};

Joueurs initJoueurs(std::string nomJoueur, int nombreIA, int jetonsDepart)
{
    Joueurs joueurs;
    for (int i = 0; i < nombreIA; i++)
    {
        std::string nomJoueur = noms[i % noms.size()] + "_"; // modulo pour être sur de ne jamais sortir du tableau
        nomJoueur += i + 'O';                                 // on ajoute un caractère la fin du prénom pour que le nom soit unique
        Joueur *joueurIA = new Joueur{
            .id = i,
            .nom = nomJoueur,
            .jetons = jetonsDepart,
        };
        joueurIA->main.reserve(5);
        joueurs.push_back(joueurIA);

        joueurIA->salutations();
    }

    Joueur *joueurReel = new Joueur{
        .id = nombreIA,
        .nom = nomJoueur,
        .jetons = jetonsDepart,
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
        for (auto carte : joueur->main)
        {
            delete carte;
        }

        delete joueur;
    }
    clearVector(joueurs);
}