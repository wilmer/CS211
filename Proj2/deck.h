#ifndef DECK_H
#define DECK_H

#include <cstddef>
#include <algorithm>  // for random_shuffle
#include <cassert>
#include <iostream>
#include <iomanip>

template <class Card>
class Deck
{
 public:

 static const size_t MAX_CARDS = 52;
 // MAX_CARDS contains capacity of deck.

 Deck(); // Default Constructor
 // pre: None.
 // post: The deck has been initialized with 52 cards:
 // 13 cards with values 1-13 for each of the four suits:'S',
 // 'H', 'D', and 'C'. Deck count has been set to 52.

 void shuffle();
 // pre: Deck has been initialized
 // post: Deck has been shuffled

 Card dealCard();
 // pre: count > 0
 // post: Card at top of deck has been removed and returned.
 // count has been decreased by 1.

 Card topCard () const { return cards[count]; }
 // pre:  count > 0
 // post: card at top of deck has been returned. deck is unchanged.

 bool hasCard() const {return count == 0;}
 //pre: none
 //post: returns true if there are no cards remaining in the deck

 int getCount() const {return count;}
 //pre: none
 //post: returns the number of cards in deck.

 const void print () const;
 // post: the contents of the deck have been written to std output.
 // Note: for debugging purposed

 private:
    Card cards[MAX_CARDS]; // Array to hold Cards
    size_t count; // Number of cards currently in deck
}; // end definition of class Deck

template <class Card>
Deck<Card>::Deck()
{
    size_t i;
    for (i = 1; i <= 13; i++)
    {              
        cards[i].chgValue(i);
        cards[i].chgSuit('D');
    }
    for (i = 14; i <= 26; i++)
    {
        cards[i].chgValue(i - 13);
        cards[i].chgSuit('S');
    }
    for (i = 27; i <= 39; i++)
    {
        cards[i].chgValue(i - 26);
        cards[i].chgSuit('C');
    }
    for (i = 40; i <= 52; i++)
    {
        cards[i].chgValue(i - 39);
        cards[i].chgSuit('H');
    }
    count = MAX_CARDS;
}

template <class Card>
void Deck<Card>::shuffle()
{
  random_shuffle (cards, cards + count);
}

template <class Card>
Card Deck<Card>::dealCard()
// pre: count > 0
// post: Card at top of deck has been removed and returned.
// count has been decreased by 1.
{
    assert (!hasCard());
    --count;
    return cards[count];
}
 
template <class Card>
const void Deck<Card>::print () const
 // post: the contents of the deck have been written to std output.
 // Note: for debugging purposed
{
    size_t j;
    for (j = 1; j <= count ; ++j)
    {
        cout << setw(2) << j << " " << cards[j];
    }    
}

#endif
