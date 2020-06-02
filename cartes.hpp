#ifndef _CARTES_HPP_
#define _CARTES_HPP_
#include <array>
#include <iostream>
#include <string>
#include <vector>

namespace cartes
{
    enum id_cartes
    {
        as = 0,
        deux,
        trois,
        quatre,
        cinq,
        six,
        sept,
        huit,
        neuf,
        dix,
        valet,
        dame,
        roi,
    };

    const std::string dos = u8"\033[34m\033[47m🂠\33[0m";
    static const std::array<std::string, 13> piques = {
        u8"\033[30m\033[47m🂡\33[0mAS",
        u8"\033[30m\033[47m🂢\33[0m2S", u8"\033[30m\033[47m🂣\33[0m3S", u8"\033[30m\033[47m🂤\33[0m4S",
        u8"\033[30m\033[47m🂥\33[0m5S", u8"\033[30m\033[47m🂦\33[0m6S", u8"\033[30m\033[47m🂧\33[0m7S",
        u8"\033[30m\033[47m🂨\33[0m8S", u8"\033[30m\033[47m🂩\33[0m9S", u8"\033[30m\033[47m🂪\33[0m10S",
        u8"\033[30m\033[47m🂫\33[0mJS", u8"\033[30m\033[47m🂭\33[0mQS",
        u8"\033[30m\033[47m🂮\33[0mKS"};
    static const std::array<std::string, 13> coeurs = {
        u8"\033[31m\033[47m🂱\33[0mAH", u8"\033[31m\033[47m🂲\33[0m2H", u8"\033[31m\033[47m🂳\33[0m3H",
        u8"\033[31m\033[47m🂴\33[0m4H", u8"\033[31m\033[47m🂵\33[0m5H", u8"\033[31m\033[47m🂶\33[0m6H",
        u8"\033[31m\033[47m🂷\33[0m7H", u8"\033[31m\033[47m🂸\33[0m8H", u8"\033[31m\033[47m🂹\33[0m9H",
        u8"\033[31m\033[47m🂺\33[0m10H", u8"\033[31m\033[47m🂻\33[0mJH", u8"\033[31m\033[47m🂽\33[0mQH",
        u8"\033[31m\033[47m🂾\33[0mKH"};

    static const std::array<std::string, 13> carreaux = {
        u8"\033[31m\033[47m🃁\33[0mAD", u8"\033[31m\033[47m🃂\33[0m2D",
        u8"\033[31m\033[47m🃃\33[0m3D", u8"\033[31m\033[47m🃄\33[0m4D",
        u8"\033[31m\033[47m🃅\33[0m5D", u8"\033[31m\033[47m🃆\33[0m6D",
        u8"\033[31m\033[47m🃇\33[0m7D", u8"\033[31m\033[47m🃈\33[0m8D",
        u8"\033[31m\033[47m🃉\33[0m9D", u8"\033[31m\033[47m🃊\33[0m10D",
        u8"\033[31m\033[47m🃋\33[0mJD", u8"\033[31m\033[47m🃍\33[0mQD",
        u8"\033[31m\033[47m🃎\33[0mKD"};
    static const std::array<std::string, 13> trefles = {
        u8"\033[30m\033[47m🃑\33[0mAC", u8"\033[30m\033[47m🃒\33[0m2C",
        u8"\033[30m\033[47m🃓\33[0m3C", u8"\033[30m\033[47m🃔\33[0m4C",
        u8"\033[30m\033[47m🃕\33[0m5C", u8"\033[30m\033[47m🃖\33[0m6C",
        u8"\033[30m\033[47m🃗\33[0m7C", u8"\033[30m\033[47m🃘\33[0m8C",
        u8"\033[30m\033[47m🃙\33[0m9C", u8"\033[30m\033[47m🃚\33[0m10C",
        u8"\033[30m\033[47m🃛\33[0mJC", u8"\033[30m\033[47m🃝\33[0mQC",
        u8"\033[30m\033[47m🃞\33[0mKC"};
} // namespace cartes

struct Carte {
    int valeur;
    std::string couleur;
    std::string icone;
    void afficher() {
        std::cout << icone;
    };
};

typedef std::vector<Carte *> Cartes;

Cartes initPaquet();
void melanger(Cartes *paquet);
void afficher(Cartes *paquet);
void clearPaquet(Cartes *paquet);

enum mains {
    Hauteur,
    Paire,
    Double_paire,
    Brelan,
    Quinte,
    Couleur,
    Full,
    Carre,
    Quinte_flush,
};

struct Combinaison {
    mains main;
    int hauteur;
    void afficher();
};

Combinaison combinaisonCartes(Cartes *main);

#endif