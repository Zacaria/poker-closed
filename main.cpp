#include <iostream>
#include "croupier.hpp"
#include "joueur.hpp"

int JETONS_DEPART = 1000;
int POT_DEPART = 2; // entre 1 et 3 généralement
int JOUEURS_IA = 8;

bool DEBUG_MODE = false;

int main()
{
    croupier::dire("========= Bienvenue ! Asseyez vous. Nous jouerons selon les règles du poker fermé :) ==========");

    /*************** Initialisation ***************/

    std::string nomJoueur = croupier::demanderNomJoueur();
    Joueurs joueurs = initJoueurs(nomJoueur, JOUEURS_IA);
    
    // Plateau
    int bouton = joueurs[0]->id; // on donne le bouton au premier joueur
    croupier::dire("Le bouton est à " + joueurs[0]->nom);

    // Mode debug pour print l'état des cartes

    // Initialiser le paquet
    // Mélanger les cartes
    Paquet paquetCartes = initPaquet();

    /*************** Jeu ***************/

    // Faire avancer le bouton
    // Pot de départ
    // Distribuer des cartes
    // Regarder les cartes
    // (AnteEnchere) Faire parler tous le joueurs jusqu'à alignement
    // Echanger (tirer du paquet, et mettre dans la défausse)
    // Enchere
    // Resolution

    croupier::dire("Merci et à bientot !!");

    return EXIT_SUCCESS;
}