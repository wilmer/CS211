#include <iostream>
#include "deck.h"   
#include "crazy8card.h"     //includes card.h
#include "player.h"

using namespace std;

int main ()
{
    Deck<crazy8card> test;

    srand( time( NULL ));     //seed the random generator

    test.shuffle();

    player human, computer, discard;

    int i;

    discard.takeCard(test.dealCard());    //discard takes one from deck

    for (i = 1; i <= 7; i++)        //give each player 7 cards
    {
        human.takeCard(test.dealCard());
    }

    for (i = 1; i <= 7; i++)
    {
        computer.takeCard(test.dealCard());
    }

    cout << "Initialization:" << endl;    //output deck, discard and hands after initialization
    cout << "Deck:" << endl;
    test.print();
    cout << "Human:" << endl;
    human.print();
    cout << "Computer:" << endl;
    computer.print();
    cout << "Discard:" << endl;
    discard.print();
    cout << endl;

    discard.takeCard(human.playCard());        //test the discard function
    discard.takeCard(computer.playCard());

    cout << "After Human and Computer Discard:" << endl;     //output
    cout << "Deck:" << endl;
    test.print();
    cout << "Human:" << endl;
    human.print();
    cout << "Computer:" << endl;
    computer.print();
    cout << "Discard:" << endl;
    discard.print();

    return 0;
}
