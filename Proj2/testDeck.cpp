#include <iostream>
#include <cstdlib>
#include "deck.h"   
#include "crazy8card.h"

int main ()
{
    Deck<crazy8card> test;

    cout << "Intialized Deck:" << endl;   //output 52 cards of deck
    test.print();

    test.shuffle();

    cout << "After Shuffle:"<< endl;     //output again after shuffle
    test.print();

    cout << "Top Card:" << endl;           //output top card
    cout << test.topCard() << endl;

    cout << "Top Card After Deal:" << endl;     //deal a card, the output top card
    cout << test.dealCard() << endl;

    return EXIT_SUCCESS;
}
