#include <iostream>
#include "game.h"    //includes others - deck, card, player, etc.

using namespace std;

int main()
{
    int start;   //variable to determine who starts first
    
    game Game;

    start = Game.turn();
    
    if (start >=4)
    {
        cout << "Computer starts!" << endl << endl;
    }
    else
    {
        cout << "You start!" << endl << endl; 
    }

    Game.playGame(start);  

    return 0;
}
