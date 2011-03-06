#include "crazy8card.h"

void crazy8card::operator =(const crazy8card& source)
//pre: an argument of crazy8card class has been inputted
//post: a card is set equal to another card
{
    if (this == &source)
        return;

    suit = source.suit;
    value = source.value;
}

bool crazy8card::bePlayed(crazy8card test, crazy8card discard) const
//pre: the players chosen card and the discard's pile top card have been determined
//post: returns true if the player's chosen card is a legal play
{
    if ((test.suit == discard.suit) && (discard.value == 8))  //an 8 is on the discard pile, so player must play new suit 
    { return true; }
    else if (test.value == 8)  //8's can always be played
    { return true; }
    else if ((test.suit == discard.suit) || (test.value == discard.value)) //card and discard have same value or suit
    { return true; }
    else
    { return false; }
}

bool crazy8card::isEight() const
//pre: a card is chosen
//post: returns true if the card's value is 8
{
    return (value == 8);
}

crazy8card crazy8card::copy (const crazy8card c1, crazy8card c2)
//create for potential problems with overload assignment operator
//pre: two cards have been chosen
//post: makes one card equal to another
{
    c2.suit = c1.suit;
    c2.value = c1.value;
    return c2;
}

std::ostream& operator << (std::ostream& outs, const crazy8card& c)
//included in this class to avoid problems described on webCT in that the overloaded << operator is
//not a member of card class, so is not an inherited function.
/*Post: Card is written to outs in the form <value> of <suit>
        (for example:  "Queen of Spades", "8 of Diamonds").
        value 1 is printed as "Ace", value 11 as "Jack", value 12 as " Queen",
        and value 13 as "King".
*/
{
    char suitname[9];
    char valuename[6];

    switch (c.getSuit())
       {
         case 'D': strcpy(suitname, "Diamonds");
	         break;
         case 'H': strcpy(suitname, "Hearts");
	         break;
         case 'C': strcpy(suitname, "Clubs");
             break;
         case 'S': strcpy(suitname, "Spades");
             break;
       }

    switch (c.getValue())
       {
         case 1: strcpy(valuename, "Ace");
            break;
         case 11: strcpy(valuename, "Jack");
            break;
         case 12: strcpy(valuename, "Queen");
            break;
         case 13: strcpy(valuename, "King");
            break;
       }

    if (c.getValue() > 1 && c.getValue() < 11)
    {
        cout << c.getValue() << " of " << suitname << endl;
    }
    else
    {
        cout << valuename << " of " << suitname << endl;
    }

    return outs;
}
 
