#include "cartes.hpp"
#include "joueur.hpp"
#include "croupier.hpp"

Carte *tirerCarte(Paquet *cartes)
{
    Carte *carte = cartes->back();
    cartes->pop_back();
    return carte;
}

void distribuerCartes(Paquet *cartes, Joueurs *joueurs)
{
    //boucle sur tous les joueurs et distribuer 5 cartes par joueurs

    for (int i = 0; i < 5; i++)
    {
        for (auto joueur : *joueurs)
        {
            Carte *carte = tirerCarte(cartes);
            joueur->main.push_back(carte);
        }
    }
    croupier::dire("J'ai fini distribuer les cartes");
}

void jouer(Paquet *cartes, Joueurs *joueurs)
{

    croupier::dire("Le jeu commence");

    distribuerCartes(cartes, joueurs);
    croupier::dire("Vous pouvez  regarder vos cartes");
    for (auto joueur : *joueurs)
    {
        joueur->montrerMain();
    }

    afficher(cartes);

    // Jouer des tours jusqu'à la fin
    //
    // Pot de départ
    // Distribuer des cartes
    // Regarder les cartes
    // (AnteEnchere) Faire parler tous le joueurs jusqu'à alignement
    // Echanger (tirer du paquet, et mettre dans la défausse)
    // Enchere
    // Resolution
    // changer l'ordre des joueurs pour Faire avancer le bouton
}