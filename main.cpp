#include <iostream>
#include "croupier.hpp"
#include "joueur.hpp"
#include "add.hpp"

int JETONS_DEPART = 1000;
int POT_DEPART = 2; // entre 1 et 3 généralement

bool DEBUG_MODE = false;

int main()
{
    // std::cout << croupier::welcome << std::endl;
    std::cout << "========= Bienvenue ! Asseyez vous. Nous jouerons selon les règles du poker fermé :) ==========" << std::endl;

    /*************** Initialisation ***************/

    std::string bo = "bobby";

    //std::cout << "add(1, 2) = " << add(1, 2) << '\n';
    Joueurs joueurs = initJoueurs(bo);
    for (Joueur *joueur : joueurs)
    {
        joueur->salutations();
    }
    

    // Initialiser les 7 IA
    // Initialiser le joueur
    // Donner le bouton
    // initJoueurs(nomJoueur)

    // Mode debug pour print l'état des cartes

    // Initialiser le paquet
    // Mélanger les cartes

    /*************** Jeu ***************/

    // Faire avancer le bouton
    // Pot de départ
    // Distribuer des cartes
    // Regarder les cartes
    // (AnteEnchere) Faire parler tous le joueurs jusqu'à alignement
    // Echanger
    // Enchere
    // Resolution

    std::cout << "Merci et à bientot !!" << std::endl;

    return EXIT_SUCCESS;
}