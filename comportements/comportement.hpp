#ifndef _COMPORTEMENT_HPP_
#define _COMPORTEMENT_HPP_
#include "../action.hpp"

namespace comportements
{
    struct BasiqueIA
    {
        bool parlerFermer();
        action parlerOuvert();
        int demanderEchange();
        int demanderMise();
            
    };
    struct PrudentIA
    {
        bool parlerFermer();
        action parlerOuvert();
        int demanderEchange();
        int demanderMise();
    };
    struct Humain
    {
        bool parlerFermer();;
        action parlerOuvert();;
        int demanderEchange();;
        int demanderMise();;
    };
} // namespace comportements

#endif