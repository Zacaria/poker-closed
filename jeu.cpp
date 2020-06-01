#include "cartes.hpp"
#include "joueur.hpp"
#include "croupier.hpp"
#include "action.hpp"
#include "jeu.hpp"
#include "constants.hpp"

int POT_DEPART = 2; // entre 1 et 3 généralement

Carte *tirerCarte(Paquet *cartes)
{
    Carte *carte = cartes->back();
    cartes->pop_back();
    return carte;
}

//boucle sur tous les joueurs et distribuer 5 cartes par joueurs
void distribuerCartes(Paquet *cartes, Joueurs joueurs)
{
    croupier::dire("Je commence à distribuer les cartes");
    for (int i = 0; i < 5; i++)
    {
        for (auto joueur : joueurs)
        {
            Carte *carte = tirerCarte(cartes);
            joueur->main.push_back(carte);
        }
    }
    croupier::dire("J'ai fini distribuer les cartes");
}

int potDepart(Joueurs joueurs)
{
    int mises = 0;
    for (auto joueur : joueurs)
    {
        joueur->miser(POT_DEPART);
        mises += POT_DEPART;
    }

    return mises;
}

Joueurs getJoueursTour(Joueurs *joueurs)
{
    Joueurs joueursTour;

    for (auto joueur : *joueurs)
    {
        if (joueur->jetons > 0)
        {
            joueursTour.push_back(joueur);
        }
    }

    return joueursTour;
}

void coucherJoueur(Joueurs *joueurs, int idToExclude)
{
    joueurs->erase(std::remove_if(joueurs->begin(), joueurs->end(),
                                  [idToExclude](Joueur *const joueur) {
                                      return joueur->id == idToExclude;
                                  }),
                   joueurs->end());
    joueurs->shrink_to_fit();
}

int demanderMise(Joueur *joueur, const int miseMin)
{
    int mise = 0;
    while (mise > joueur->jetons || mise < miseMin)
    {
        croupier::dire("Vous misez combien ? Pour rappel, vous avez " + std::to_string(joueur->jetons) + " jetons");
        std::cin >> mise;
        if (joueur->jetons < mise)
        {
            croupier::dire("Vous ne pouvez pas miser plus de " + std::to_string(joueur->jetons) + " jetons");
        }
        if (mise < miseMin)
        {
            croupier::dire("La mise minimum est de " + std::to_string(miseMin));
        }
    }
    return mise;
}

void echanges(Paquet *cartes, Joueurs *joueurs)
{
    croupier::dire("C'est le moment d'échanger des cartes");
    for (auto joueur : *joueurs)
    {
        if (joueur->isIA == false || constants::DEBUG_MODE == true)
        {
            afficher(&joueur->main);
        }
        int nbCartesDonnees = joueur->demanderEchange();

        std::vector<Carte *> cartesDonnees;
        for (int i = 0; i < nbCartesDonnees; i++)
        {
            cartesDonnees.push_back(tirerCarte(&joueur->main));
        }
        // On sépare bien les deux boucles car on ne veut pas risquer de rendre une carte donnée au joueur
        for (int i = 0; i < nbCartesDonnees; i++)
        {
            joueur->main.push_back(tirerCarte(cartes));
        }
        cartes->insert(cartes->end(), cartesDonnees.begin(), cartesDonnees.end());

        if (joueur->isIA == false || constants::DEBUG_MODE == true)
        {
            croupier::dire("Voici " + std::to_string(nbCartesDonnees) + " cartes");
            afficher(&joueur->main);
        }
    }
}

void encheres(TourJeu *tour)
{
    for (auto joueur : tour->joueurs)
    {
        if (tour->ouvert == false)
        {
            // Parler
            tour->ouvert = joueur->parlerFermer();
            std::cout << "est ce ouvert: " << tour->ouvert << std::endl;
            // Miser si ouverture
            if (tour->ouvert == true)
            {
                int mise = demanderMise(joueur, 1);
                bool reussi = joueur->miser(mise);
                if (reussi == false)
                { // on fait tapis
                    tour->mises += joueur->jetons;
                    std::cout << joueur->nom << " : Je fais tapis !" << std::endl;
                }
                else
                {
                    tour->mises += mise;
                }
                tour->miseIndiv = mise;
            }
        }
        else
        {

            // Parler
            action reponse = joueur->parlerOuvert(tour->miseIndiv);

            // consequence
            switch (reponse)
            {
            case action::suivre:
                joueur->miser(tour->miseIndiv); //verifier que le joueur peut miser
                tour->mises += tour->miseIndiv;
                break;
            case action::coucher:
                coucherJoueur(&tour->joueurs, joueur->id);
                break;
            case action::relancer:
                // demander la relance de combien ?
                int mise;
                mise = demanderMise(joueur, tour->miseIndiv);
                bool reussi;
                reussi = joueur->miser(mise);
                if (reussi == false)
                { // on fait tapis
                    tour->mises += joueur->jetons;
                    std::cout << joueur->nom << " : Je fais tapis !" << std::endl;
                }
                else
                {
                    tour->mises += mise;
                }
                tour->miseIndiv = mise;
                break;
            case action::tapis:
                joueur->miser(joueur->jetons);
                tour->mises += joueur->jetons;
                std::cout << joueur->nom << " : Je fais tapis !" << std::endl;
                if (joueur->jetons > tour->miseIndiv)
                {
                    tour->miseIndiv = joueur->jetons;
                }
                break;
            }
        }
    }
}

void ramasserCartes(Paquet *cartes, Joueurs joueurs)
{
    for (auto joueur : joueurs)
    {
        cartes->insert(cartes->end(), joueur->main.begin(), joueur->main.end());
        Main mainVide;
        joueur->main = mainVide;
    }
    afficher(cartes);
    std::cout << "paquet taille" << cartes->size() << std::endl;
}

// Sortir les joueurs ruinés
void sortirLesRuines(Joueurs *joueurs)
{
    joueurs->erase(std::remove_if(joueurs->begin(), joueurs->end(),
                                  [](Joueur *const joueur) {
                                      if (joueur->jetons == 0)
                                      {
                                          croupier::dire("Ciao " + joueur->nom);
                                      }
                                      return joueur->jetons == 0;
                                  }),
                   joueurs->end());
    joueurs->shrink_to_fit();
}

// Le premier passe en dernier et on décale tout le monde
void decalerJoueurs(Joueurs *joueurs)
{
    std::rotate(joueurs->begin(), joueurs->begin() + 1, joueurs->end());
}

void jouer(Paquet *cartes, Joueurs *joueurs)
{
    croupier::dire("Le jeu commence");

    // Début d'un boucle qui sort quand il ne reste plus qu'un joueur qui joue
    for (size_t i = 0; i < 5; i++)
    {
        croupier::dire("Début du tour " + std::to_string(i));

        TourJeu *tour = new TourJeu();
        tour->joueurs = getJoueursTour(joueurs);

        distribuerCartes(cartes, tour->joueurs);

        croupier::dire("Envoyez le pot de départ !");
        tour->mises += potDepart(tour->joueurs);

        croupier::dire("Total mises " + std::to_string(tour->mises));

        croupier::dire("Vous pouvez regarder vos cartes");

        for (auto joueur : tour->joueurs)
        {
            if (joueur->isIA == false || constants::DEBUG_MODE == true)
            { // on regarde que la main du joueur réel, mais en debug on regarde tout le monde
                joueur->montrerMain();
            }
        }

        // premières enchères
        encheres(tour);

        croupier::dire("Total mises " + std::to_string(tour->mises));

        // échanges
        echanges(cartes, joueurs);

        // deuxièmes enchères
        encheres(tour);

        croupier::dire("Total mises " + std::to_string(tour->mises));

        // Fin du coup : calcul des combinaisons des cartes
        // donner la mise du tour au gagnant au gagnant

        // Récupérer les cartes dans le paquet
        ramasserCartes(cartes, tour->joueurs);

        croupier::dire("Donez moi vos cartes pour les remettre dans le paquet");

        std::cout << joueurs->size() << std::endl;

        // Finde la boucle, on détermine qui n'a plus d'argent et sort du jeu
        sortirLesRuines(joueurs);
        decalerJoueurs(joueurs);
        croupier::dire("Maintenant c'est " + joueurs->front()->nom + " qui commence");
        delete tour;
    }

    // Jouer des tours jusqu'à la fin
    //
    // Pot de départ
    // Distribuer des cartes
    // Regarder les cartes
    // (AnteEnchere) Faire parler tous le joueurs jusqu'à alignement
    // Echanger (tirer du paquet, pas de défausse, il y a juste le reste du paquet, et les cartes a ne pas donner)
    // Enchere
    // Resolution
    // changer l'ordre des joueurs pour Faire avancer le bouton
}