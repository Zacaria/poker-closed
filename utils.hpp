#ifndef _UTILS_HPP_
#define _UTILS_HPP_
#include <vector>

unsigned getRandomSeed();

template <typename T>
void clearVector(std::vector<T> *toClear)
{
    toClear->erase(toClear->begin(), toClear->end());
    toClear->shrink_to_fit();
}

#endif
