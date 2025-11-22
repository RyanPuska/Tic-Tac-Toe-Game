#include "board.h"
#include <iostream>
#include <vector>
using namespace std;

//constructor that assigns each spot on the board with a -
//when game starts
Board::Board()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            board[i][j] = SPACE;
        }
    }
}

//function that displays board
void Board::displayBoard()
{
    cout << endl;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "=============" << endl;
    cout << "1 2 3 4 5 6 7 " << endl << endl;
}


//function for player to choose their spot
void Board::choosePlace()
{
    int playerChoice;
    int turn = 0;

    while (true)
    {
        //determines player
        if (turn % 2 == 0)
        {
            currentPlayer = RED;
            cout << "It is Red's turn. In which column would" <<
                " you like to move (-1 to exit)?";
        }
        else
        {
            currentPlayer = YELLOW;
            cout << "It is Yellow's turn. In which column would" <<
                " you like to move (-1 to exit)?";
        }
        cin >> playerChoice;

        //checks for valid input
        if (playerChoice != -1 && (playerChoice < 1 || playerChoice > 7))
        {
            cout << "Invalid move, try again. " << endl;
            continue;
        }

        if (playerChoice == -1)
        {
            return;
        }

        //checks rows to put player's piece on,
        bool full = false;
        for (int j = ROWS - 1; j >= 0; j--)
        {
            if (board[j][playerChoice - 1] == SPACE)
            {
                board[j][playerChoice - 1] = currentPlayer;
                full = true;
                break;
            }
        }

        //checks if column is full or not
        if (full == false)
        {
            cout << "Invalid move, try again. " << endl;
            continue;
        }
        displayBoard();

        //if there is a winner, display message and return
        if (checkWin())
        {
            if (turn % 2 == 0)
            {
                cout << "Red wins!" << endl;
            }
            else
            {
                cout << "Yellow wins!" << endl;
            }
            return;
        }

        //if there is a tie, display message and return
        if (checkTie())
        {
            cout << "Game over. Tie game." << endl;
            return;
        }
        turn++;
    }
}

//function to check win
bool Board::checkWin() const
{
    //checks vertically
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (board[i][j] != SPACE && board[i][j] == board[i + 1][j] &&
                board[i][j] == board[i + 2][j] && board[i][j] == board[i + 3][j])
            {
                return true;
            }
        }
    }

    //checks horizontally
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] != SPACE && board[i][j] == board[i][j + 1] &&
                board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3])
            {
                return true;
            }
        }
    }

    //checks diagonally down right
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] != SPACE && board[i][j] == board[i + 1][j + 1] &&
                board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3])
            {
                return true;
            }
        }
    }

    //checks diagonally down left
    for (int i = 0; i < 3; i++)
    {
        for (int j = COLUMNS - 1; j >= 3; j--)
        {
            if (board[i][j] != SPACE && board[i][j] == board[i + 1][j - 1] &&
                board[i][j] == board[i + 2][j - 2] && board[i][j] == board[i + 3][j - 3])
            {
                return true;
            }
        }
    }
    return false;
}

//function to check tie
bool Board::checkTie() const
{
    int count = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (board[i][j] == RED || board[i][j] == YELLOW)
            {
                count++;
                //if count equals maximum number of places, its a tie
                if (count == (ROWS * COLUMNS))
                {
                    return true;
                }
            }
        }
    }
    return false;
}