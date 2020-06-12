#include <iostream>
#include "comportement.hpp"
#include "../action.hpp"

bool comportements::BasiqueIA::parlerFermer()
{
    std::cout << "J'ouvre" << std::endl;
    return true;
}

action comportements::BasiqueIA::parlerOuvert(int jetons, int miseIndiv)
{
    return action::suivre;
}
int comportements::BasiqueIA::demanderEchange()
{
    // if combinaison > 3 return 0 sinon return 2
    return 2;
}
int comportements::BasiqueIA::demanderMise(int jetons, const int miseMin)
{
    return miseMin + 100 > jetons ? miseMin : miseMin + 50;
}