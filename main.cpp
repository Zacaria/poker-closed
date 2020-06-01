#include <iostream>
#include "croupier.hpp"
#include "joueur.hpp"
#include "utils.hpp"
#include "jeu.hpp"
#include "constants.hpp"

int main()
{
    croupier::dire(croupier::welcome);
    croupier::dire("========= Bienvenue ! Asseyez vous. Nous jouerons selon les règles du poker fermé :) ==========");

    /*************** Initialisation ***************/

    std::string nomJoueur = croupier::demanderNomJoueur();
    Joueurs joueurs = initJoueurs(nomJoueur);

    int bouton = joueurs[0]->id; // on donne le bouton au premier joueur // pas besoin parce que c'est ordonné, on a juste besoin du numéro du tour
    croupier::dire("Le bouton est à " + joueurs[0]->nom);

    Paquet paquetCartes = initPaquet();
    if (constants::DEBUG_MODE == true)
    {
        afficher(&paquetCartes);
    }

    melanger(&paquetCartes);
    croupier::dire("Le paquet de cartes est tout neuf ! Laissez moi le mélanger");
    if (constants::DEBUG_MODE == true)
    {
        afficher(&paquetCartes);
    }

    /*************** Jeu ***************/
    jouer(&paquetCartes,&joueurs);

    /*************** Fin, Nettoyage ***************/

    croupier::dire("La partie est terminée, bien joué :)");

    clearPaquet(&paquetCartes);
    croupier::dire("Je range les cartes...");

    clearJoueurs(&joueurs);
    croupier::dire("Merci et à bientot !!");

    return EXIT_SUCCESS;
}