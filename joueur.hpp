#ifndef _JOUEUR_HPP_
#define _JOUEUR_HPP_
#include <iostream>
#include <string>
#include <vector>
#include "cartes.hpp"
#include "croupier.hpp"
#include "jeu.hpp"

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
    };
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
        if(nbJetons > jetons) {
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

        std::string reponse = "";

        while (reponse != "Yes" && reponse != "No")
        {
            std::getline(std::cin, reponse);
            std::cout << "reponse est: " << reponse << std::endl;
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
        if (isIA)
        {
            return action::suivre; // action par défaut à changer quand on mettra de l'intelligence
        }
        croupier::dire("Que voulez-vous faire ? (suivre/coucher/relancer/tapis)");
        std::string reponse = "";

        while (reponse != "suivre" && reponse != "coucher" && reponse != "relancer" && reponse != "tapis")
        {
            std::getline(std::cin, reponse);
            std::cout << "reponse est: " << reponse << std::endl;
            if (reponse != "suivre" && reponse != "coucher" && reponse != "relancer" && reponse != "tapis")
            {
                croupier::dire("Les réponses possibles sont suivre, coucher, relancer ou tapis) :)");
                croupier::dire("N'oubliez pas que vous pouvez quitter à tout moment en appuyant sur Ctrl+C");
            }
        }

        if(miseIndiv>jetons && (reponse == "suivre" || reponse == "relancer")){
            std::cout << nom << " : je n'ai plus assez de jetons (^^)', je fais tapis" << std::endl;
            return action::tapis;
        }

        switch (reponse)
        {
        case "suivre":
            return action::suivre;
        case "coucher":
            return action::coucher;
        case "relancer":
            return action::relancer;
        case "tapis":
            return action::tapis;
        }
    }
};

typedef std::vector<Joueur *> Joueurs;

Joueurs initJoueurs(std::string nomJoueur, int nombreIA, int jetonsDepart);
void clearJoueurs(Joueurs *joueurs);

#endif