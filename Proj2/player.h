#ifndef PLAYER_H
#define PLAYER_H

#include "crazy8card.h"
#include "deck.h"

class player
{
public:

    static const size_t MAX_CARDS = 52;

    player();

    void takeCard (crazy8card cards);

    crazy8card pickCard (int cardnum);

    crazy8card playCard();

    bool noCards() const {return count == 0;}

    void print();

    crazy8card getHand(int cardnum);

    int getHandVal(int cardnum);

    void getHandSuit(int cardnum);

    int getCount();

    void restore();

    void chgSuit (char suite);

    crazy8card compcard(int cardnum);

    bool bePlayed(crazy8card c1, crazy8card c2);

private:

    crazy8card hand[MAX_CARDS];
    size_t count;    

};

#endif
