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
    std::cout << "Hey ! moi c'est " << nom << ", mon id : " << id << " et je suis " << comportement << std::endl;
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
    std::cout << " Je mise " << nbJetons << " jetons" << std::endl;
    return true;
}

bool Joueur::parlerFermer()
{
    std::cout << nom << " : ";
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
    return false;
}

action Joueur::parlerOuvert(const int miseIndiv)
{
    std::cout << nom << " : ";
    if (comportement == "basique")
    {
        return basique.parlerOuvert(jetons, miseIndiv);
    }
    if (comportement == "prudent")
    {
        return prudent.parlerOuvert(jetons, miseIndiv);
    }
    if (comportement == "humain")
    {
        return humain.parlerOuvert(jetons, miseIndiv);
    }
    return action::suivre;
}

int Joueur::demanderEchange()
{
    std::cout << nom << " : ";
    if (comportement == "basique")
    {
        return basique.demanderEchange();
    }
    if (comportement == "prudent")
    {
        return prudent.demanderEchange();
    }
    if (comportement == "humain")
    {
        return humain.demanderEchange();
    }
    return 0;
}

int Joueur::demanderMise(const int miseMin)
{
    std::cout << nom << " : ";
    if (comportement == "basique")
    {
        return basique.demanderMise(jetons, miseMin);
    }
    if (comportement == "prudent")
    {
        return prudent.demanderMise(jetons, miseMin);
    }
    if (comportement == "humain")
    {
        return humain.demanderMise(jetons, miseMin);
    }
    return 1;
}
