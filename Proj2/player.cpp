#include "player.h"
#include <iomanip>

using namespace std;

player::player()
//Constructor
{
    count = 0;
}

bool player::bePlayed(crazy8card c1, crazy8card c2)
//pre:none
//post: returns true or false if a card can legally be played
{
    return c1.bePlayed(c1, c2);
}

void player::takeCard(crazy8card cards)
//pre:none
//post: count of cards increased by one, card is added to hand
{
    ++count;
    hand[count] = cards;
}

crazy8card player::pickCard(int cardnum)
//pre: none
//post: returns a card
{
    return (hand[cardnum]);
}

crazy8card player::playCard()
//pre: player has chosen to play a card
//post: chosen card is returned and hand count is decremented by one
{
    int cardnum;
    crazy8card temp;
    cout << endl << "Choose card # to play:" << endl;
    cin >> cardnum;
    assert (cardnum <= count);   //swap card choice with card at end of hand
    temp = hand[count];
    hand[count] = hand[cardnum];
    hand[cardnum] = temp;
    --count;
    return (hand[count+1]);
}

crazy8card player::compcard(int cardnum)
//pre: computer strategy determines a card can be played
//post: a card is returned and the count is decremented by one
{
    crazy8card temp;
    temp = hand[count];
    hand[count] = hand[cardnum];
    hand[cardnum] = temp;
    --count;
    return (hand[count+1]);
}    

void player::restore()
//restores the count when a card can't be played
//pre: none
//post: count increased by one
{
    count++;
}

void player::print()
//pre: none
//post: cards in hand are output to screen
{
    int i;
    cout << setw(2) << " # " << "Card" << endl;
    for (i = 1; i <= count; i++)
    {
        cout << setw(2) << i << " ";
        cout << getHand(i);
    }
}

crazy8card player::getHand(int cardnum)
//pre: none
//post: returns a particular card
{
    return hand[cardnum];
}

int player::getHandVal(int cardnum)
//pre: none
//post: returns the value of a particular card
{
    return hand[cardnum].getValue();
}

void player::getHandSuit(int cardnum)
//pre: none
//post: returns the suit of a particular card
{
    hand[cardnum].getSuit();
}

int player::getCount()
//pre: none
//post: returns the current # of cards in a hand 
{
    return count;
}

void player::chgSuit(char suite)
//pre: an 8 has been played
//post: the suit of the card is changed
{
    hand[count].chgSuit(suite);
}


