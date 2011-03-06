#ifndef CRAZY8CARD_H
#define CRAZY8CARD_H

#include "card.h"

using namespace std;

class crazy8card : public Card  //inherits class Card
{
public:

    bool bePlayed(crazy8card test, crazy8card discard) const;
    bool isEight() const;
    crazy8card copy (const crazy8card c1, crazy8card c2);
    void operator =(const crazy8card& source);
};
std::ostream& operator << (std::ostream& outs, const crazy8card& c);

#endif
