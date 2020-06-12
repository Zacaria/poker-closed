#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "constants.hpp"
namespace croupier
{
    void dire(std::string texte)
    {
        if (constants::DEBUG_MODE == false) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        std::cout << "Croupy : " << texte << std::endl;
    }

    std::string demanderNomJoueur()
    {
        dire("Je m'appelle Croupy, et vous comment vous appelez vous ?");

        if (constants::DEBUG_MODE == true) {
            return "Test";
        }

        std::string nomJoueur = "";

        while (nomJoueur.length() < 1)
        {
            std::getline(std::cin, nomJoueur);
            if (nomJoueur.length() < 1)
            {
                dire("Veuillez entrer un nom :)");
                dire("N'oubliez pas que vous pouvez quitter à tout moment en appuyant sur Ctrl+C");
            }
        }

        dire("Enchanté "+ nomJoueur + ", commencons !");

        return nomJoueur;
    }
}
