// Test d'affichage des cartes :
#include <iostream>
#include "cartes.hpp"

int main()
{
    std::cout << "Dos de la carte : " << cartes::dos << std::endl << std::endl;

    std::cout << "Les trèfles : ";
    for ( const auto& c : cartes::trefles )
        std::cout << c << " ";
    std::cout << std::endl << std::endl;

    std::cout << "Les piques : ";
    for ( const auto& c : cartes::piques )
        std::cout << c << " ";
    std::cout << std::endl << std::endl;

    std::cout << "Les coeurs : ";
    for ( const auto& c : cartes::coeurs )
        std::cout << c << " ";
    std::cout << std::endl << std::endl;

    std::cout << "Les carreaux : ";
    for ( const auto& c : cartes::carreaux )
        std::cout << c << " ";
    std::cout << std::endl << std::endl;

    std::cout << "Valet de trèfle : " << cartes::trefles[cartes::valet] << std::endl;
    
    return EXIT_SUCCESS;

}