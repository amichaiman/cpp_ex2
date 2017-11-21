#include <iostream>
#include "Game.h"
using namespace std;

int main()
{
    Game wari;
    
    wari.setCurPlayer('N');
    while(wari.gameWinner() == ' ')
    {
        wari.playTurn();
        wari.switchPlayer();
        wari.printStatus();
    }

    wari.printWinner();
}
