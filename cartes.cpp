#include <array>
#include <iostream>
#include "cartes.hpp"
#include "utils.hpp"
#include "random"

Paquet initPaquet()
{
    Paquet cartes;

    for (int valeur = 0; valeur < cartes::piques.size(); valeur++)
    {
        Carte *carte = new Carte{
            .valeur = valeur,
            .couleur = "piques",
            .icone = cartes::piques[valeur],
        };

        cartes.push_back(carte);
    }

    for (int valeur = 0; valeur < cartes::coeurs.size(); valeur++)
    {
        Carte *carte = new Carte{
            .valeur = valeur,
            .couleur = "coeurs",
            .icone = cartes::coeurs[valeur],
        };
        cartes.push_back(carte);
    }

    for (int valeur = 0; valeur < cartes::carreaux.size(); valeur++)
    {
        Carte *carte = new Carte{
            .valeur = valeur,
            .couleur = "carreaux",
            .icone = cartes::carreaux[valeur],
        };
        cartes.push_back(carte);
    }

    for (int valeur = 0; valeur < cartes::trefles.size(); valeur++)
    {
        Carte *carte = new Carte{
            .valeur = valeur,
            .couleur = "trefles",
            .icone = cartes::trefles[valeur],
        };
        cartes.push_back(carte);
    }
    return cartes;
}

void melanger(Paquet *paquet)
{
    shuffle(paquet->begin(), paquet->end(), std::default_random_engine(getRandomSeed()));
}

void afficher(Paquet *paquet)
{
    for (auto carte : *paquet)
    {
        carte->afficher();
        std::cout << " ";
    }

    std::cout << std::endl;
}

void clearPaquet(Paquet *paquet)
{
    for (auto carte : *paquet)
    {
        delete carte;
    }
    clearVector(paquet);
}
