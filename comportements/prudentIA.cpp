#include <iostream>
#include "comportement.hpp"
#include "../action.hpp"

bool comportements::PrudentIA::parlerFermer()
{
    std::cout << "Check" << std::endl;
    return false;
}

action comportements::PrudentIA::parlerOuvert(int jetons, int miseIndiv)
{
    return action::suivre;
}
int comportements::PrudentIA::demanderEchange()
{
    return 0;
}
int comportements::PrudentIA::demanderMise(int jetons, const int miseMin)
{
    return miseMin;
}
