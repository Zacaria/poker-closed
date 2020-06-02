#include <iostream>
#include "comportement.hpp"

bool comportements::BasiqueIA::parlerFermer()
{
    std::cout << "J'ouvre" << std::endl;
    return true;
}
