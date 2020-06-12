#include <array> // shuffle
#include <iostream>
#include <map>
#include <algorithm> // sort
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
int getMaxValeur(int hauteurA, int hauteurB)
{
    if (getHauteur(hauteurA) > getHauteur(hauteurB))
    {
        return getHauteur(hauteurA);
    }
    return getHauteur(hauteurB);
}

int isCarre(Cartes *main)
{
    std::map<int, int> valeurs;

    for (auto carte : *main)
    {
        valeurs[carte->valeur]++;
    }

    bool carre = false;
    int hauteurCarre = -1;
    for (auto const &[hauteur, occurences] : valeurs)
    {
        if (occurences == 4)
        {
            carre = true;
            hauteurCarre = getHauteur(hauteur);
        }
    }
    if (carre == true)
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
    int hauteurFull = -1;
    for (auto const &[hauteur, occurences] : valeurs)
    {

        // deuxième paire
        if (occurences == 3)
        {
            brelan = true;
            hauteurFull = getHauteur(hauteur);
        }
        // première paire
        if (occurences == 2)
        {
            paire = true;
        }
    }

    if (paire == true && brelan == true)
    {
        return hauteurFull;
    }

    return -1;
}

int isCouleur(Cartes *main)
{
    std::map<std::string, int> couleurs;

    int hauteurMax = -1;
    for (auto carte : *main)
    {
        couleurs[carte->couleur]++;
        hauteurMax = getMaxValeur(carte->valeur, hauteurMax);
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
    std::array<int, 5> valeursAsZero;
    std::array<int, 5> valeursAsTreize;
    int j = 0;

    for (auto carte : *main)
    {
        valeursAsZero.at(j) = carte->valeur;
        valeursAsTreize.at(j) = getHauteur(carte->valeur);
        j++;
    }
    std::sort(valeursAsZero.begin(), valeursAsZero.end());
    std::sort(valeursAsTreize.begin(), valeursAsTreize.end());

    auto isValeursConsecutives = [](std::array<int, 5> vals) {
        bool isConsecutives = true;
        int hauteur = -1;
        for (int i = 0; i < vals.size(); i++)
        {
            if (i > 0 && (vals[i] - vals[i - 1] != 1))
            {
                isConsecutives = false;
            }
            hauteur = getMaxValeur(hauteur, vals[i]);
        }

        if (isConsecutives == true)
        {
            return hauteur;
        }

        return -1;
    };

    int isConsecutiveZero = isValeursConsecutives(valeursAsZero);
    int isConsecutiveTreize = isValeursConsecutives(valeursAsTreize);

    if (isConsecutiveZero != -1)
    {
        return isConsecutiveZero;
    }
    if (isConsecutiveTreize != -1)
    {
        return isConsecutiveTreize;
    }

    return -1;
}

int isBrelan(Cartes *main)
{
    std::map<int, int> valeurs;

    for (auto carte : *main)
    {
        valeurs[carte->valeur]++;
    }

    bool brelan = false;
    int hauteurBrelan = -1;

    for (auto const &[hauteur, occurences] : valeurs)
    {
        if (occurences == 3)
        {
            brelan = true;
            hauteurBrelan = getHauteur(hauteur);
        }
    }

    if (brelan == true)
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

    bool paire = false;
    bool doublePaire = false;
    int hauteurPaire = -1;
    for (auto const &[hauteur, occurences] : valeurs)
    {
        // deuxième paire
        if (occurences == 2 && paire == true && doublePaire == false)
        {
            doublePaire = true;
            hauteurPaire = getHauteur(hauteur) > getHauteur(hauteurPaire) ? getHauteur(hauteur) : getHauteur(hauteurPaire);
        }
        // première paire
        if (occurences == 2 && paire == false && doublePaire == false)
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
    int hauteurPaire = -1;
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

// Quinte flush est quinte et couleur
int isQuinteFlush(Cartes *main)
{
    int isQuinteMain = -1;
    int isCouleurMain = -1;
    isQuinteMain = isQuinte(main);
    isCouleurMain = isCouleur(main);

    if (isQuinteMain != -1 && isCouleurMain != -1)
    {
        return isQuinteMain;
    }

    return -1;
}

int getHauteurMain(Cartes *main)
{
    int hauteurMax = -1;
    for (auto carte : *main)
    {
        hauteurMax = getMaxValeur(carte->valeur, hauteurMax);
    }
    return hauteurMax;
}

Combinaison combinaisonCartes(Cartes *main)
{
    // l'ordre des if est important
    int resultQuinteFlush = isQuinteFlush(main);
    if (resultQuinteFlush != -1)
    {
        return Combinaison{Quinte_flush, resultQuinteFlush};
    }

    int resultIsCarre = isCarre(main);
    if (resultIsCarre != -1)
    {
        return Combinaison{Carre, resultIsCarre};
    }

    int resultIsFull = isFull(main);
    if (resultIsFull != -1)
    {
        return Combinaison{Full, resultIsFull};
    }

    int resultIsCouleur = isCouleur(main);
    if (resultIsCouleur != -1)
    {
        return Combinaison{Couleur, resultIsCouleur};
    }

    int resultIsQuinte = isQuinte(main);
    if (resultIsQuinte != -1)
    {
        return Combinaison{Quinte, resultIsQuinte};
    }

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

    int hauteurMain = getHauteurMain(main);
    return Combinaison{Hauteur, hauteurMain};
}

std::string idCarteToString(int id)
{
    switch (id)
    {
    case cartes::as:
    case 13:
        return "as";
    case cartes::deux:
        return "deux";
    case cartes::trois:
        return "trois";
    case cartes::quatre:
        return "quatre";
    case cartes::cinq:
        return "cinq";
    case cartes::six:
        return "six";
    case cartes::sept:
        return "sept";
    case cartes::huit:
        return "huit";
    case cartes::neuf:
        return "neuf";
    case cartes::dix:
        return "dix";
    case cartes::valet:
        return "valet";
    case cartes::dame:
        return "dame";
    case cartes::roi:
        return "roi";
    default:
        return " carte inconnue";
    }
}

void Combinaison::afficher()
{
    if (main == Hauteur)
    {
        std::cout << "Hauteur de " << idCarteToString(hauteur) << std::endl;
    }
    if (main == Paire)
    {
        std::cout << "Paire de " << idCarteToString(hauteur) << std::endl;
    }
    if (main == Double_paire)
    {
        std::cout << "Double_paire de " << idCarteToString(hauteur) << std::endl;
    }
    if (main == Brelan)
    {
        std::cout << "Brelan de " << idCarteToString(hauteur) << std::endl;
    }
    if (main == Quinte)
    {
        std::cout << "Quinte de " << idCarteToString(hauteur) << std::endl;
    }
    if (main == Couleur)
    {
        std::cout << "Couleur de " << idCarteToString(hauteur) << std::endl;
    }
    if (main == Full)
    {
        std::cout << "Full de " << idCarteToString(hauteur) << std::endl;
    }
    if (main == Carre)
    {
        std::cout << "Carre de " << idCarteToString(hauteur) << std::endl;
    }
    if (main == Quinte_flush)
    {
        std::cout << "Quinte_flush de " << idCarteToString(hauteur) << std::endl;
    }
}
