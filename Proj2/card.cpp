#include "card.h"

#include <fstream>
#include <cctype>
#include <iostream>
#include <cstring>

using namespace std;

void Card::chgValue(int val)
//pre: a new value for a card has been inputted
//post: value of card has been changed
{
    value = val;
}

void Card::chgSuit(char suite)
//pre: a new suit for a card has been inputted
//post: suit of card has been changed
{
    suit = suite;
}

std::ostream& operator << (std::ostream& outs, const Card& c)
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
