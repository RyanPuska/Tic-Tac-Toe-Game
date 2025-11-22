#include <iostream>
using namespace std;
#ifndef BOARD_H
#define BOARD_H

class Board {
public:
    //function declarations
    Board();
    void displayBoard();
    void choosePlace();
    bool checkWin() const;
    bool checkTie() const;


private:
    //private variables
    static const int ROWS = 6;
    static const int COLUMNS = 7;
    static const char SPACE = '-';
    static const char RED = 'R';
    static const char YELLOW = 'Y';
    char board[ROWS][COLUMNS];
    char currentPlayer;

};

#endif
