#include "Game.h"


Game::Game()
:winner(' '),whosTurn('N')
{
    p1.setName('N');
    p2.setName('S');
    print();
    
}

Game::Game(const Game &g)
{}

Game::~Game()
{}

Player &Game::curPlayer()
{
    if (whosTurn == 'N')
        return p1;
    else
        return p2;
}
bool Game::isValidInput(const string action)
{
    if (action == "QUIT")
        return true;
    
    if (action.length() != 1)
        return false;
    
    if (!islower(action[0]))
        return false;
    
    if (action[0]-'a' < 0 || action[0] -'a' >= Player::NUM_OF_SLOTS)
        return false;
    if (curPlayer().board[action[0]-'a'].getNumOfDiscs() == 0)
        return false;
    
    return true;
}
void Game::print() const
{
    cout << p1.getName() << ":";
    
    for (int i=Player::NUM_OF_SLOTS-1; i>=0; i--)
        cout << "\t[" << (char)(i+'a') << "] " << p1.board[i].getNumOfDiscs();
    
    cout << endl;
    cout << p2.getName() << ":";
    for (int i=0; i<Player::NUM_OF_SLOTS; i++)
        cout << "\t[" << (char)(i+'a') << "] " << p2.board[i].getNumOfDiscs();
    cout << endl;
}


void Game::playTurn()
{
    if (curPlayer().boardIsEmpty())
        return;
    
    string action;
    cout << curPlayer().getName() << ":\t";
    cin >> action;
    
    while (!isValidInput(action))
    {
        cout << "Invalid move; the game awaits a valid move.\n";
        cout << curPlayer().getName() << ":\t";
        cin >> action;
    }
    
    
    if (action == "QUIT")
    {
        switchPlayer();
        winner = whosTurn;
        switchPlayer();
        return;
    }
    int origPlayer = whosTurn;
    
    startWalking(action[0]-'a');
    
    setCurPlayer(origPlayer);
    checkForWinners();
}

void Game::checkForWinners()
{
    if (curPlayer().getDiscsInCaptivity() >= WINNING_MIN)
    {
        switchPlayer();
        if (curPlayer().getDiscsInCaptivity() >= WINNING_MIN)
            winner = 'T';
        else
        {
            switchPlayer();
            winner = whosTurn;
        }
    }
}
void Game::startWalking(int curSpot)
{
    int steps = curPlayer().board[curSpot].getNumOfDiscs();
    char origPlayer = whosTurn;
    curPlayer().board[curSpot].setNumOfDiscs(0);
    curSpot++;
    
    while(steps > 0)
    {
        if (curSpot == Player::NUM_OF_SLOTS)
        {
            switchPlayer();
            curSpot %= Player::NUM_OF_SLOTS;
        }
        curPlayer().board[curSpot]++;
        curSpot++;
        steps--;
    }
    curSpot--;
    if (whosTurn != origPlayer)
    {
        int collectedDiscs = collectBackwards(curSpot);
        setCurPlayer(origPlayer);
        curPlayer().addDiscsToCaptivity(collectedDiscs);
    }
}
void Game::setCurPlayer(const char c)
{
    whosTurn = c;
}

void Game::switchPlayer()
{
    if (whosTurn == 'N')
        whosTurn = 'S';
    else
        whosTurn = 'N';
}

int Game::collectBackwards(int spot)
{
    if (spot == -1)
        return 0;
    
    int discs = curPlayer().board[spot].getNumOfDiscs();
    if (discs == 2 || discs == 3)
    {
        curPlayer().board[spot].setNumOfDiscs(0);
        return discs + collectBackwards(spot-1);
    }
    return 0;
}
char Game::gameWinner() const
{
    return winner;
}

void Game::printStatus() const
{
    cout << p1.getDiscsInCaptivity() << endl;
    print();
    cout << p2.getDiscsInCaptivity() << endl;
}

void Game::printWinner() const
{
    if (winner == 'T')
        cout << "The game ends in a tie." << endl;
    else
        cout << winner << " wins the game." << endl;
}
