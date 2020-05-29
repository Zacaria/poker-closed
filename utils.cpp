#include <chrono>
#include <vector>
#include "utils.hpp"

unsigned getRandomSeed() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    return seed;
}
