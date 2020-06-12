#include <iostream>
#include "comportement.hpp"
#include "../croupier.hpp"
#include "../action.hpp"

bool comportements::Humain::parlerFermer() {
    std::cout << "Voulez-vous ouvrir (oui/non)" << std::endl;

    std::string reponse;

    while (reponse != "oui" && reponse != "non")
    {
        std::getline(std::cin, reponse);
        if (reponse != "oui" && reponse != "non")
        {
            croupier::dire("Les réponses possibles sont oui ou non :)");
            croupier::dire("N'oubliez pas que vous pouvez quitter à tout moment en appuyant sur Ctrl+C");
        }
    }
    return reponse == "oui";
}

action comportements::Humain::parlerOuvert(int jetons, int miseIndiv)
{
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
        std::cout << " : je n'ai plus assez de jetons (^^)', je fais tapis" << std::endl;
        return action::tapis;
    }

    else if (reponse == "suivre")
    {
        std::cout << " : Je suis !" << std::endl;
        return action::suivre;
    }
    else if (reponse == "relancer")
    {
        std::cout << " : Je relance !" << std::endl;
        return action::relancer;
    }
    else if (reponse == "tapis")
    {
        std::cout << " : Tapis !" << std::endl;
        return action::tapis;
    }
    else if (reponse == "coucher")
    {
        std::cout << " : Je me couche" << std::endl;
        return action::coucher;
    }
    else
    {
        std::cout << "ERREUR, action non reconnue, je me couche" << std::endl;
        return action::coucher;
    }
}
int comportements::Humain::demanderEchange()
{
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
        std::cout << " : servi" << std::endl;
    }
    else
    {
        std::cout << " : " << nbrEchange << " cartes" << std::endl;
    }
    return nbrEchange;
}
int comportements::Humain::demanderMise(int jetons, const int miseMin)
{
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
