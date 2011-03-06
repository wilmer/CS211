#ifndef CARD_H
#define CARD_H

#include <fstream>
#include <cctype>
#include <iostream>

using namespace std;

class Card
{   public:
      Card (char csuit = 'S', int cvalue = 1): 
            suit (toupper(csuit)), value (cvalue) {}
      const char getSuit() const {return suit;}
      const int getValue() const {return value;}
      void chgSuit(char suite);
      void chgValue(int val);
   
    protected:
      char suit;
      int value;

};
std::ostream& operator << (std::ostream& outs, const Card& c);
/*Post: Card is written to outs in the form <value> of <suit>
        (for example:  "Queen of Spades", "8 of Diamonds").
        value 1 is printed as "Ace", value 11 as "Jack", value 12 as " Queen",
        and value 13 as "King".
*/

#endif
