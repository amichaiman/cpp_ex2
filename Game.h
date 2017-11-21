#ifndef _GAME_H
#define _GAME_H

#include <iostream>
#include <cctype>
#include "Player.h"

using namespace std;
class Game

{
public:
    Game();
    Game(const Game &g);
    ~Game();
    bool isValidInput(const string input);//returns true if input is valid, false otherwise
    void print() const;
    void playTurn();
    char gameWinner() const; //returns winners letter, or 'space' if game not over yet
    Player &curPlayer();    //returns witch player is currently playing
    void setCurPlayer(const char c);
    void switchPlayer();
    void startWalking(int curSpot);
    int collectBackwards(int spot);
    void printStatus() const;
    void checkForWinners();
    void printWinner() const;
private:
    Player p1;
    Player p2;
    char winner;
    char whosTurn;
    const int WINNING_MIN = 24;
};

#endif
