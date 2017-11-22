#ifndef _GAME_H
#define _GAME_H

#include <iostream>
#include <cctype>
#include "Player.h"

using namespace std;
class Game
{
public:
    Game();         //c'tor
    Game(const Game &g);    //copy c'tor
    ~Game();            //d'tor
    bool isValidInput(const string input);//returns true if input is valid, false otherwise
    void print() const;     //prints both players boards
    void playTurn();            //manages current players turn
    char gameWinner() const; //returns winners letter, or 'space' if game not over yet
    Player &curPlayer();    //returns witch player is currently playing
    void setCurPlayer(const char c);    //sets current player 
    void switchPlayer();                //switchs from current player to other plater
    void startWalking(int curSpot);     //moves discs from current slot to ascending slots
    int collectBackwards(int spot);     //if final ascending slot has 2 or 3 discs, discs are collected recursivly. as long as they as well have 2 or 3 discs
    void printStatus() const;       //prints board + number of discs in captivity
    void checkForWinners();         //checks for winners, and sets winner accordingly
    void printWinner() const;       //prints message declaring winner
private:
    Player p1;  //player 'N'
    Player p2;  //player 'S'
    char winner;        //gets values: ' ' - for no winner. 'N'/'S' for winning player. 'T' for tie
    char whosTurn;     
    static const int WINNING_MIN = 24; //minimum number of discs to declare winner
};

#endif
