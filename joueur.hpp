#ifndef _JOUEUR_HPP_
#define _JOUEUR_HPP_
#include <iostream>
#include <string>
#include <vector>
#include "cartes.hpp"
#include "croupier.hpp"
#include "action.hpp"

struct Joueur
{
    int id;
    std::string nom;
    int jetons;
    Main main;
    bool isIA;
    void salutations()
    {
        std::cout << "Hey ! moi c'est " << nom << ", mon id : " << id << std::endl;
    }
    void montrerMain()
    {
        std::cout << "Je suis " << nom << " id : " << id << " ";
        for (auto carte : main)
        {
            carte->afficher();
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    bool miser(int nbJetons)
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
    bool parlerFermer()
    {
        if (isIA == true)
        {
            std::cout << "Je suis " << isIA << ", j'ouvre" << std::endl;
            return false; // action par défaut à changer quand on mettra de l'intelligence
        }
        std::cout << "Voulez-vous ouvrir (Yes/No)" << std::endl;

        std::string reponse;

        while (reponse != "Yes" && reponse != "No")
        {
            
            std::getline(std::cin, reponse);
            if (reponse != "Yes" && reponse != "No")
            {
                croupier::dire("Les réponses possibles sont Yes ou No :)");
                croupier::dire("N'oubliez pas que vous pouvez quitter à tout moment en appuyant sur Ctrl+C");
            }
        }
        return reponse == "Yes";
    }
    action parlerOuvert(const int miseIndiv)
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
        else {
            std::cout << "ERREUR, action non reconnue, je me couche" << std::endl;
            return action::coucher;
        }
    };
    int demanderEchange() {
        if(isIA == true) {
            return 2;
        }
        int nbrEchange = -1;
        croupier::dire("Vous pouvez demander entre 0 et 3 cartes");
        while (nbrEchange < 0 || nbrEchange > 3) {
            std::cin >> nbrEchange;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            if(nbrEchange < 0 || nbrEchange > 3) {
                croupier::dire("Vous pouvez demander entre 0 et 3 cartes");
                croupier::dire("N'oubliez pas que vous pouvez quitter à tout moment en appuyant sur Ctrl+C");
            }
        }

        if (nbrEchange == 0) {
            std::cout << nom << " : servi" << std::endl;
        } else  {
            std::cout << nom << " : " << nbrEchange << " cartes" << std::endl;
        }
        return nbrEchange;
    };
};

typedef std::vector<Joueur *> Joueurs;

Joueurs initJoueurs(std::string nomJoueur);
void clearJoueurs(Joueurs *joueurs);

#endif