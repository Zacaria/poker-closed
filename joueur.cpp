#include <iostream>
#include <string>
#include <array>
#include <random>
#include "joueur.hpp"
#include "utils.hpp"
#include "constants.hpp"
#include "comportements/comportement.hpp"
#include "comportements/basiqueIA.cpp"
#include "comportements/prudentIA.cpp"
#include "comportements/humain.cpp"

std::array<std::string, 8> noms = {
    "Yahya", "Anna", "Laila", "Idir", "Hamadi", "Gael", "Foued", "Marie"};

comportements::BasiqueIA basique{};
comportements::PrudentIA prudent{};
comportements::Humain humain{};

Joueurs initJoueurs(std::string nomJoueurReel)
{
    Joueurs joueurs;
    std::string comportement;
    for (int i = 0; i < constants::JOUEURS_IA; i++)
    {
        if (i % 2 == 0)
        {
            comportement = "basique";
        }
        if (i % 2 == 1)
        {
            comportement = "prudent";
        }
        std::string nomJoueur = noms[i % noms.size()] + "_"; // modulo pour être sur de ne jamais sortir du tableau
        nomJoueur += i + 'O';                                // on ajoute un caractère la fin du prénom pour que le nom soit unique
        Joueur *joueurIA = new Joueur{
            .id = i,
            .nom = nomJoueur,
            .jetons = constants::JETONS_DEPART,
            .isIA = true,
            .comportement = comportement,
        };
        joueurIA->main.reserve(5);
        joueurs.push_back(joueurIA);

        joueurIA->salutations();
    }

    Joueur *joueurReel = new Joueur{
        .id = constants::JOUEURS_IA,
        .nom = nomJoueurReel,
        .jetons = constants::JETONS_DEPART,
        .isIA = false,
        .comportement = "humain",
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
        delete joueur;
    }
    clearVector(joueurs);
}

void Joueur::salutations()
{
    std::cout << "Hey ! moi c'est " << nom << ", mon id : " << id << std::endl;
}

void Joueur::montrerMain()
{
    std::cout << "Je suis " << nom << " id : " << id << " ";
    for (auto carte : main)
    {
        carte->afficher();
        std::cout << " ";
    }
    std::cout << std::endl;
}

bool Joueur::miser(int nbJetons)
{
    if (nbJetons > jetons)
    {
        jetons = 0;
        return false;
    }
    jetons -= nbJetons;
    std::cout << nom << " : Je mise " << nbJetons << " jetons" << std::endl;
    return true;
}

bool Joueur::parlerFermer()
{
    if (comportement == "basique")
    {
        return basique.parlerFermer();
    }
    if (comportement == "prudent")
    {
        return prudent.parlerFermer();
    }
    if (comportement == "humain")
    {
        return humain.parlerFermer();
    }
    // if (isIA == true)
    // {
    //     return comportement.parlerFermer();
    // }
    // std::cout << "Voulez-vous ouvrir (Yes/No)" << std::endl;

    // std::string reponse;

    // while (reponse != "Yes" && reponse != "No")
    // {
    //     std::getline(std::cin, reponse);
    //     if (reponse != "Yes" && reponse != "No")
    //     {
    //         croupier::dire("Les réponses possibles sont Yes ou No :)");
    //         croupier::dire("N'oubliez pas que vous pouvez quitter à tout moment en appuyant sur Ctrl+C");
    //     }
    // }
    // return reponse == "Yes";
}

action Joueur::parlerOuvert(const int miseIndiv)
{
    if (isIA == true)
    {
        return action::suivre; // action par défaut à changer quand on mettra de l'intelligence
    }
    std::string reponse;

    while (reponse != "suivre" && reponse != "coucher" && reponse != "relancer" && reponse != "tapis")
    {
        croupier::dire("Que voulez-vous faire ? (suivre/coucher/relancer/tapis)");
        std::getline(std::cin, reponse);
        if (reponse != "suivre" && reponse != "coucher" && reponse != "relancer" && reponse != "tapis")
        {
            croupier::dire("Les réponses possibles sont suivre, coucher, relancer ou tapis) :)");
            croupier::dire("N'oubliez pas que vous pouvez quitter à tout moment en appuyant sur Ctrl+C");
        }
    }

    if (miseIndiv > jetons && (reponse == "suivre" || reponse == "relancer"))
    {
        std::cout << nom << " : je n'ai plus assez de jetons (^^)', je fais tapis" << std::endl;
        return action::tapis;
    }

    else if (reponse == "suivre")
    {
        std::cout << nom << " : Je suis !" << std::endl;
        return action::suivre;
    }
    else if (reponse == "relancer")
    {
        std::cout << nom << " : Je relance !" << std::endl;
        return action::relancer;
    }
    else if (reponse == "tapis")
    {
        std::cout << nom << " : Tapis !" << std::endl;
        return action::tapis;
    }
    else if (reponse == "coucher")
    {
        std::cout << nom << " : Je me couche" << std::endl;
        return action::coucher;
    }
    else
    {
        std::cout << "ERREUR, action non reconnue, je me couche" << std::endl;
        return action::coucher;
    }
}

int Joueur::demanderEchange()
{
    if (isIA == true)
    {
        return 2;
    }
    int nbrEchange = -1;
    croupier::dire("Vous pouvez demander entre 0 et 3 cartes");
    while (nbrEchange < 0 || nbrEchange > 3)
    {
        std::cin >> nbrEchange;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        if (nbrEchange < 0 || nbrEchange > 3)
        {
            croupier::dire("Vous pouvez demander entre 0 et 3 cartes");
            croupier::dire("N'oubliez pas que vous pouvez quitter à tout moment en appuyant sur Ctrl+C");
        }
    }

    if (nbrEchange == 0)
    {
        std::cout << nom << " : servi" << std::endl;
    }
    else
    {
        std::cout << nom << " : " << nbrEchange << " cartes" << std::endl;
    }
    return nbrEchange;
}

int Joueur::demanderMise(const int miseMin)
{
    if (isIA == true)
    {
        return 2;
    }

    int mise = 0;
    while (mise > jetons || mise < miseMin)
    {
        croupier::dire("Vous misez combien ? Pour rappel, vous avez " + std::to_string(jetons) + " jetons");
        std::cin >> mise;
        if (jetons < mise)
        {
            croupier::dire("Vous ne pouvez pas miser plus de " + std::to_string(jetons) + " jetons");
        }
        if (mise < miseMin)
        {
            croupier::dire("La mise minimum est de " + std::to_string(miseMin));
        }
    }
    return mise;
}
