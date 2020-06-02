#include <array> // shuffle
#include <iostream>
#include <map>
#include "cartes.hpp"
#include "utils.hpp"
#include "random"

Cartes initPaquet()
{
    Cartes cartes;

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

void melanger(Cartes *paquet)
{
    shuffle(paquet->begin(), paquet->end(), std::default_random_engine(getRandomSeed()));
}

void afficher(Cartes *paquet)
{
    for (auto carte : *paquet)
    {
        carte->afficher();
        std::cout << " ";
    }

    std::cout << std::endl;
}

void clearPaquet(Cartes *paquet)
{
    for (auto carte : *paquet)
    {
        delete carte;
    }
    clearVector(paquet);
}

int compteMaxOccurences(Cartes *main)
{
    std::map<int, int> valeurs;

    // on compte le nombre de valeurs
    for (auto carte : *main)
    {
        valeurs[carte->valeur]++;
    }

    int maxOccurence;
    for (auto const &[hauteur, occurences] : valeurs)
    {
        if (occurences > maxOccurence)
        {
            maxOccurence = occurences;
        }
    }
    return maxOccurence;
}

// la hauteur de l'as est 13
// sinon les autres cartes ont la même hauteur que leur valeur
int getHauteur(int valeur)
{
    if (valeur == 0)
    {
        return 13;
    }
    return valeur;
}

// traite le cas de l'as en terme de valeur
int getMaxValeur(Carte *carteA, int hauteurCompare)
{
    if (getHauteur(carteA->valeur) > getHauteur(hauteurCompare))
    {
        return getHauteur(carteA->valeur);
    }
    return getHauteur(hauteurCompare);
}

int isQuinteFlush(Cartes *main)
{
}

int isCarre(Cartes *main)
{
    std::map<int, int> valeurs;

    for (auto carte : *main)
    {
        valeurs[carte->valeur]++;
    }

    bool carre;
    int hauteurCarre;
    for (auto const &[hauteur, occurences] : valeurs)
    {
        if (occurences == 4)
        {
            carre = true;
            hauteurCarre = getHauteur(hauteur);
        }
    }
    if (carre)
    {
        return hauteurCarre;
    }
    return -1;
}

int isFull(Cartes *main)
{
    std::map<int, int> valeurs;

    for (auto carte : *main)
    {
        valeurs[carte->valeur]++;
    }

    bool paire = false;
    bool brelan = false;
    int hauteurFull;
    std::cout << "paire " << paire << " brelan : " << brelan << std::endl;
    for (auto const &[hauteur, occurences] : valeurs)
    {

        std::cout << "hauteur " << hauteur << " occurences" << occurences << std::endl;
        // deuxième paire
        if (occurences == 3)
        {

            std::cout << "occurences = 3 ?" << occurences << std::endl;
            brelan = true;
            hauteurFull = getHauteur(hauteur);
        }
        // première paire
        if (occurences == 2)
        {
            paire = true;
        }
    }

    std::cout << "paire " << paire << " brelan : " << brelan << std::endl;
    if (paire == true && brelan == true)
    {
        return hauteurFull;
    }

    return -1;
}

int isCouleur(Cartes *main)
{
    int nbCouleurs;
    std::map<std::string, int> couleurs;

    int hauteurMax;
    for (auto carte : *main)
    {
        couleurs[carte->couleur]++;
        hauteurMax = getMaxValeur(carte, hauteurMax);
    }

    if (couleurs.size() != 1)
    {
        return -1;
    }

    return hauteurMax;
}

// quinte est une suite
// a noter que l'as peut compter comme 0 et 13
int isQuinte(Cartes *main)
{
}

int isBrelan(Cartes *main)
{
    std::map<int, int> valeurs;

    for (auto carte : *main)
    {
        valeurs[carte->valeur]++;
    }

    bool brelan;
    int hauteurBrelan;

    for (auto const &[hauteur, occurences] : valeurs)
    {
        if (occurences == 3)
        {
            brelan = true;
            hauteurBrelan = getHauteur(hauteur);
        }
    }

    if (brelan)
    {
        return hauteurBrelan;
    }

    return -1;
}

int isDoublePaire(Cartes *main)
{
    std::map<int, int> valeurs;

    for (auto carte : *main)
    {
        valeurs[carte->valeur]++;
    }

    bool paire;
    bool doublePaire;
    int hauteurPaire;
    for (auto const &[hauteur, occurences] : valeurs)
    {
        // deuxième paire
        if (occurences == 2 && paire == true)
        {
            doublePaire = true;
            hauteurPaire = getHauteur(hauteur) > getHauteur(hauteurPaire) ? getHauteur(hauteur) : getHauteur(hauteurPaire);
        }
        // première paire
        if (occurences == 2 && doublePaire == false)
        {
            paire = true;
            hauteurPaire = getHauteur(hauteur);
        }
    }
    if (doublePaire)
    {
        return hauteurPaire;
    }

    return -1;
}

int isPaire(Cartes *main)
{
    std::map<int, int> valeurs;

    for (auto carte : *main)
    {
        valeurs[carte->valeur]++;
    }

    bool paire;
    int hauteurPaire;
    for (auto const &[hauteur, occurences] : valeurs)
    {
        if (occurences == 2)
        {
            paire = true;
            hauteurPaire = getHauteur(hauteur);
        }
    }
    if (paire)
    {
        return hauteurPaire;
    }
    return -1;
}

int getHauteur(Cartes *main)
{
    int hauteurMax;
    for (auto carte : *main)
    {
        hauteurMax = getMaxValeur(carte, hauteurMax);
    }
    return hauteurMax;
}

Combinaison combinaisonCartes(Cartes *main)
{
    // l'ordre des if est important
    int resultIsCarre = isCarre(main);
    if (resultIsCarre != -1)
    {
        return Combinaison{Carre, resultIsCarre};
    }

    int resultIsFull = isFull(main);
    if (resultIsFull != -1)
    {
        std::cout << "resultisfull" << resultIsFull << std::endl;
        return Combinaison{Full, resultIsFull};
    }

    int resultIsCouleur = isCouleur(main);
    if (resultIsCouleur != -1)
    {
        return Combinaison{Couleur, resultIsCouleur};
    }

    // int resultIsQuinte = isQuinte(main);
    // if (resultIsQuinte != -1)
    // {
    //     return Combinaison{Quinte, resultIsQuinte};
    // }

    int resultIsBrelan = isBrelan(main);
    if (resultIsBrelan != -1)
    {
        return Combinaison{Brelan, resultIsBrelan};
    }

    int resultIsDoublePaire = isDoublePaire(main);
    if (resultIsDoublePaire != -1)
    {
        return Combinaison{Double_paire, resultIsDoublePaire};
    }

    int resultIsPaire = isPaire(main);
    if (resultIsPaire != -1)
    {
        return Combinaison{Paire, resultIsPaire};
    }

    int hauteurMain = getHauteur(main);
    return Combinaison{Hauteur, hauteurMain};
}
