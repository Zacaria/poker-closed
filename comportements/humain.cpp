#include <iostream>
#include "comportement.hpp"
#include "../croupier.hpp"

bool comportements::Humain::parlerFermer() {
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

