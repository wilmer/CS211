#ifndef GAME_H
#define GAME_H

#include "deck.h"
#include "player.h"
#include <ctime>

class game
{
public:
    int turn();
    char nameSuit();
    void playGame(const int start);
    void humanturn();
    void compturn();
    game ();
    bool winner ();
    bool pwinner (player player);
    int score (player player);

private:
    Deck<crazy8card> deck;
    player human, computer, discard;

};

#endif
