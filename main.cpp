#include <iostream>
#include "Game.h"
using namespace std;

int main()
{
    Game wari;
    
    wari.setCurPlayer('N'); //'N' gets first move
    
    wari.playTurn();
    while(wari.gameWinner() == ' ') //as long as no winner was declared
    {
        wari.switchPlayer();
        wari.printStatus();
        wari.playTurn();
    }

    wari.printWinner();
}
