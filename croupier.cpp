#include <iostream>
#include <string>
#include <thread>
#include <chrono>
namespace croupier
{
    void dire(std::string texte)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << texte << std::endl;
    }

    std::string demanderNomJoueur()
    {
        dire("Je m'appelle Croupy, et vous comment vous appelez vous ?");

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

        dire(nomJoueur + " je suis enchanté, c'est parti !");

        return nomJoueur;
    }
} // namespace croupier
