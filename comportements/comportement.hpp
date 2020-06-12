#ifndef _COMPORTEMENT_HPP_
#define _COMPORTEMENT_HPP_
#include "../action.hpp"

namespace comportements
{
    struct BasiqueIA
    {
        bool parlerFermer();
        action parlerOuvert(int jetons, int miseIndiv);
        int demanderEchange();
        int demanderMise(int jetons, const int miseMin);
    };
    struct PrudentIA
    {
        bool parlerFermer();
        action parlerOuvert(int jetons, int miseIndiv);
        int demanderEchange();
        int demanderMise(int jetons, const int miseMin);
    };
    struct Humain
    {
        bool parlerFermer();
        action parlerOuvert(int jetons, int miseIndiv);
        int demanderEchange();
        int demanderMise(int jetons, const int miseMin);
    };
} // namespace comportements

#endif