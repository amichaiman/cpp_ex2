#include "Player.h"

Player::Player(const char theName):captivity(0),name(theName)
{}

Player::Player():captivity(0)
{}

Player::Player(const Player &p):captivity(p.getDiscsInCaptivity())
{}

Player::~Player()
{
}

void Player::setName(const char theName)
{
    name = theName;
}

char Player::getName() const
{
    return name;
}
int Player::getDiscsInCaptivity() const
{
    return captivity;
}
void Player::setDiscsInCaptivity(const int n)
{
    captivity = n;
}

void Player::addDiscsToCaptivity(const int n)
{
    captivity += n;
}

bool Player::boardIsEmpty() const
{
    for (int i=0; i<NUM_OF_SLOTS; i++)
        if (board[i].getNumOfDiscs() != 0)
            return false;
    return true;
}
