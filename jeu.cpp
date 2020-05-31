#include "cartes.hpp"
#include "joueur.hpp"
#include "croupier.hpp"

int POT_DEPART = 2; // entre 1 et 3 généralement

Carte *tirerCarte(Paquet *cartes)
{
    Carte *carte = cartes->back();
    cartes->pop_back();
    return carte;
}

//boucle sur tous les joueurs et distribuer 5 cartes par joueurs
void distribuerCartes(Paquet *cartes, Joueurs *joueurs)
{
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

int potDepart(Joueurs *joueurs)
{
    int mises = 0;
    for (auto joueur : *joueurs)
    {
        joueur->miser(POT_DEPART);
        mises += POT_DEPART;
    }

    return mises;
}

Joueurs getJoueursTour(Joueurs *joueurs){
    Joueurs joueursTour;

    for(auto joueur : *joueurs){
        if(joueur->jetons > 0){
            joueursTour.push_back(joueur);
        }
    }

    return joueursTour;
}

void jouer(Paquet *cartes, Joueurs *joueurs, bool debug)
{

    croupier::dire("Le jeu commence");

    // Début d'un boucle qui sort quand il ne reste plus qu'un joueur qui joue
    int mises = 0;
    int miseIndiv = 0;
    bool ouvert = false;
    Joueurs joueursTour = getJoueursTour(joueurs);


    distribuerCartes(cartes, &joueursTour);

    croupier::dire("Envoyez le pot de départ !");
    mises += potDepart(&joueursTour);

    croupier::dire("Total mises " + std::to_string(mises));

    croupier::dire("Vous pouvez regarder vos cartes");

    for (auto joueur : joueursTour)
    {
        if (joueur->isIA == false || debug == true)
        { // on regarde que la main du joueur réel, mais en debug on regarde tout le monde
            joueur->montrerMain();
        }
    }

    // premières enchères
    for (auto joueur : joueursTour)
    {
        if (ouvert == false)
        {
            // Parler
            ouvert = joueur->parlerFermer();
            std::cout << "est ce ouvert: " << ouvert << std::endl;
            // Miser si ouverture
            if (ouvert == true)
            {
                int mise = 0;
                while (mise > joueur->jetons - 1 || mise < 1)
                {
                    croupier::dire("Vous ouvrez avec combien ? Pour rappel, vous avez " + std::to_string(joueur->jetons) + " jetons");
                    std::cin >> mise;
                    std::cout << "mise: " << mise << std::endl;
                    if (joueur->jetons < mise)
                    {
                        croupier::dire("Vous ne pouvez pas miser plus de " + std::to_string(joueur->jetons) + " jetons");
                    }
                }
                bool reussi = joueur->miser(mise);
                if (reussi == false)
                { // on fait tapis
                    mise += joueur->jetons;
                    std::cout << joueur->nom << " : Je fais tapis !" << std::endl;
                }
                else
                {
                    mises += mise;
                }
                miseIndiv = mise;
                croupier::dire("Total mises " + std::to_string(mises));
            }
        }
        else
        {
            // Parler
            action reponse = joueur->parlerOuvert(miseIndiv);

            // consequence
            switch (reponse)
            {
            case action::suivre:
                joueur->miser(miseIndiv); //verifier que le joueur peut miser
                mises += miseIndiv;
                break;
            case action::coucher:
                /* code */
                break;
            case action::relancer:
                /* code */
                break;
            case action::tapis:
                /* code */
                break;
            default:
                break;
            }
        }
    }

    // échanges

    // deuxièmes enchères

    // Fin du coup : calcul des combinaisons des cartes

    // Récupérer les cartes dans le paquet
    // ramasser

    // Finde la boucle, on détermine qui n'a plus d'argent et sort du jeu

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