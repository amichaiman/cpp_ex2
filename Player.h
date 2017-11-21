#ifndef _PLAYER_H
#define _PLAYER_H

#include "Slot.h"

class Player
{
public:
    static const int NUM_OF_SLOTS = 6;
    Slot board[NUM_OF_SLOTS];
    
    Player(const char theName); //c'tor
    Player();       //c'tor
    Player(const Player &p);    //copy c'tor
    ~Player();      //d'tor
    void setName(const char theName);   //set players name
    char getName() const;               //returns players name
    int getDiscsInCaptivity() const;   //returns number of discs in captivity
    void setDiscsInCaptivity(const int n);  //set number of discs in captivity to n
    void addDiscsToCaptivity(const int n); //add n number of discs to players captivity
    bool boardIsEmpty() const;  //returns true if all slots are empty
private:
    int captivity;  //number of discs in players captivity
    char name;      //players name
};

#endif
