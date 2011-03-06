#include "game.h"
#include <ctime>
#include <iostream>

int game::turn()
//pre: none.
//post: a number from 1-6 is returned and used to determine who starts.
{
      srand( time( NULL ));
      int d;
      d = 1 + rand () % 6; 
      return d;
}

char game::nameSuit()
//pre: the human player has played an 8
//post: the suit is changed.
{
    char suit;
    cout << endl << "What suit would you like to change to?" << endl;
    cout << "Enter D (Diamonds), H (Hearts), C (Clubs), or S (Spades): ";
    cin >> suit;
    assert (suit == 'D' || 'H' || 'C' || 'S');
    discard.chgSuit(suit); 
}

void game::playGame(const int start)
//pre: deck, discard and players hands have been initialized, start has been determined by function turn
//post: continues to play game until function winner returns true
{
    do {
        if (start >= 4)
        {
            compturn();
            humanturn();
        }
        else
        {
            humanturn();
            compturn();
        }
    } while (!winner());
}

void game::humanturn()
//pre: initialization from function start has occured and game is in play
//post: player has chosen to play or pick up a card, checks if winner
{
    int choice;

    crazy8card c;

    cout << endl << "Top of Discard Pile:" << endl;       //output current card on top of discard pile
    cout << discard.pickCard(discard.getCount()) << endl;

    cout << "Your cards:" << endl;    //displays humans card
    human.print();

    cout << endl << "1. Play a card" << endl;  //provide choices
    cout << "2. Draw a card" << endl;
    cout << endl << "Your choice: ";
    cin >> choice;

    assert (choice == 1 || choice == 2);

    if (choice == 1)
    {
        c = human.playCard();        //play a card
        if (human.bePlayed(c, discard.pickCard(discard.getCount())))
        {
            discard.takeCard(c);
            if (c.getValue() == 8)
                { nameSuit(); }
        }
        else       //not a legal card to be played
        {
            cout << endl << "Card can't be played!" << endl;
            human.restore();
            humanturn();
        }
    }        
    else       //take a card from deck
    {
        human.takeCard(deck.dealCard());
    }

    if(pwinner(human)) //check if winner
    {
        cout << endl << "You win!" << endl;
        cout << "The computer's score is: " << score(computer) << endl;
    }
}

void game::compturn()
//pre: initialization from function start has occured and game is in play
//post: computer has chosen to play or pick up a card, checks if winner
{
    int p, d, l;
    char suit;

    for (p = 1; p <= computer.getCount(); ++p)
    {
        if (computer.bePlayed(computer.getHand(p), discard.pickCard(discard.getCount())) && computer.getHandVal(p) != 8)     
        //increments through cards and plays the first legal card that isn't an 8
        {
            discard.takeCard(computer.compcard(p));
            l = p;
            if (l == computer.getCount())
                {l = 0;}
            break;
        }
        else if (computer.getHandVal(p) == 8) //plays an 8 if no other legal cards
        {
            discard.takeCard(computer.compcard(p));
            srand( time( NULL ));
            d = 1 + rand () % 4;
            switch (d)            //choose randomly which suit to change to
            {
                case 1:
                    suit = 'D';
                    break;
                case 2:
                    suit = 'H';
                    break;
                case 3:
                    suit = 'S';
                    break;
                case 4:
                    suit = 'C';
                    break;
                default:
                    suit = 'S';
            } 
            discard.chgSuit(suit);
            l = p;
            if (l == computer.getCount())
                {l = 0;}
            break;
        }
        l = p;
        if (l == 1)
            {l = 0;}
    }

    if (l == computer.getCount())    //computer cannot play a card, so it picks from deck
    {
        computer.takeCard(deck.dealCard());
    }
    
    if(pwinner(computer)) //check if winner
    {
        cout << endl << "Computer wins." << endl;
        cout << "Your score is: " << score(human) << endl;    
    }
}

game::game ()
//pre: deck (with 52 cards) and hands (with zero cards) have been constructed
//post: each player has 7 cards and discard pile has one
{
    srand( time( NULL )); 

    deck.shuffle();

    int i;

    for (i = 1; i <= 7; i++)
    {
        human.takeCard(deck.dealCard());
    }

    for (i = 1; i <= 7; i++)
    {
        computer.takeCard(deck.dealCard());
    }

    discard.takeCard(deck.dealCard());
}

bool game::pwinner(player player)
//pre: none
//post: returns true if a player has no cards, false otherwise
{
    if (player.noCards())
        { return true;}
    else
        { return false;}
}

bool game::winner()
//pre: none
//post: true or false is returned depending on whether or not each player or the deck still has cards
//or not.
{
    if ((human.noCards()) || (computer.noCards()))
        {return true;}
    else if (deck.getCount() == 0)
        {
            cout << endl << "Deck Out!  No winner." << endl;
            return true;
        }
    else
        {return false;}        
}

int game::score (player player)
//pre: a player has won (no cards) and the other player has cards remaining.
//post: a score based on the losing players remaining cards is returned.
{
    int k;
    int score = 0;
    for (k = 1; k <= player.getCount(); ++k)
    {
        if (player.getHandVal(k) ==  8) 
        {
            score += -50;
        }
        else if (player.getHandVal(k) >= 10)
        {
            score += -10;
        }
        else
        {
            score += -1 * player.getHandVal(k);
        }
    }
    return score;
}
