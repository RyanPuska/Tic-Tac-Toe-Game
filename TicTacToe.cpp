/*Ryan Puska    5/3
research a command/function to enhance the game (changing color)*/

#include <iostream>
#include <windows.h>    //header file added to change color of background and/or text
using namespace std;

char choice;    //character for number input
bool winf = false;  //boolean to determine a tie

void title(void);       //prototypes builds "mail" system, transfer of data
void display(void);
void chooseX(void);
void chooseO(void);
void win(void);
void resetBoard(void);

char X = 'X';   //character X that will replace the squares
char O = 'O';   //character O that will replace the squares

char sq1 = '1';     //numbers to create the board
char sq2 = '2';
char sq3 = '3';
char sq4 = '4';
char sq5 = '5';
char sq6 = '6';
char sq7 = '7';
char sq8 = '8';
char sq9 = '9';

int main()
{

    char playAgain;
    do {
        resetBoard();
        title();            //calls title and display function
        display();

        for (int turn = 0; turn < 9; ++turn)
        {
            if (turn % 2 == 0)
            {
                chooseX();
            }
            else
            {
                chooseO();
            }
            display();
            win();

            if (winf) break;
        }

        if (!winf)
        {  //if no winner after all turns, display tie
            cout << system("Color 76") << "\n Tie game!\n" << system("Color 70");   //changes color of text to yellow when a tie
        }

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');

    return 0;
}

void title(void)
{
    cout << "Ryan Puska\t4/17\n";                             //displays title
    cout << "Title Lab 7\tTic Tac Toe Project\n";
}

void display(void)
{
    cout << "\n" << sq1 << "\t" << sq2 << "\t" << sq3 << "\t\n\n";
    cout << sq4 << "\t" << sq5 << "\t" << sq6 << "\t\n\n";
    cout << sq7 << "\t" << sq8 << "\t" << sq9 << "\t";
}

void resetBoard(void)
{
    sq1 = '1'; sq2 = '2'; sq3 = '3';
    sq4 = '4'; sq5 = '5'; sq6 = '6';
    sq7 = '7'; sq8 = '8'; sq9 = '9';
    winf = false;
}

void chooseX(void)
{
    system("Color 74");     //changes text color to red when it's player X's turn
    cout << "\n\n\t Player X, please choose a square: ";
    cin >> choice;
    if (sq1 == choice)      //if the value of square 1 is equal to choice, square 1 will be replaced with char X
    {
        sq1 = X;
    }
    else if (sq2 == choice) //if the value of square 2 is equal to choice, square 2 will be replaced with char X, and so on
    {
        sq2 = X;
    }
    else if (sq3 == choice)
    {
        sq3 = X;
    }
    else if (sq4 == choice)
    {
        sq4 = X;
    }
    else if (sq5 == choice)
    {
        sq5 = X;
    }
    else if (sq6 == choice)
    {
        sq6 = X;
    }
    else if (sq7 == choice)
    {
        sq7 = X;
    }
    else if (sq8 == choice)
    {
        sq8 = X;
    }
    else if (sq9 == choice)
    {
        sq9 = X;
    }
    else
    {
        cout << "\nPlease choose a number 1 - 9. ";     //else, tells the user to enter a number 1-9
    }
}

void chooseO(void)
{
    system("Color 71"); //changes text color to blue when it's player O's turn
    cout << "\n\n\t Player O, please choose a square: ";
    cin >> choice;
    if (sq1 == choice)      //if the value of square 1 is equal to choice, square 1 will be replaced with char O
    {
        sq1 = O;
    }
    else if (sq2 == choice)     //if the value of square 2 is equal to choice, square 2 will be replaced with char O, like the chooseX function
    {
        sq2 = O;
    }
    else if (sq3 == choice)
    {
        sq3 = O;
    }
    else if (sq4 == choice)
    {
        sq4 = O;
    }
    else if (sq5 == choice)
    {
        sq5 = O;
    }
    else if (sq6 == choice)
    {
        sq6 = O;
    }
    else if (sq7 == choice)
    {
        sq7 = O;
    }
    else if (sq8 == choice)
    {
        sq8 = O;
    }
    else if (sq9 == choice)
    {
        sq9 = O;
    }
    else
    {
        cout << "\nPlease choose a number 1-9.";
    }
}

void win() {
    // Checking all winning conditions
    bool gameWon = false;
    char winner = '\0';

    // Horizontal wins
    if ((sq1 == sq2 && sq2 == sq3) || (sq4 == sq5 && sq5 == sq6) || (sq7 == sq8 && sq8 == sq9))
    {
        gameWon = true;
        winner = (sq1 == sq2 && sq2 == sq3) ? sq1 : (sq4 == sq5 && sq5 == sq6) ? sq4 : sq7;
    }
    // Vertical wins
    else if ((sq1 == sq4 && sq4 == sq7) || (sq2 == sq5 && sq5 == sq8) || (sq3 == sq6 && sq6 == sq9))
    {
        gameWon = true;
        winner = (sq1 == sq4 && sq4 == sq7) ? sq1 : (sq2 == sq5 && sq5 == sq8) ? sq2 : sq3;
    }
    // Diagonal wins
    else if ((sq1 == sq5 && sq5 == sq9) || (sq3 == sq5 && sq5 == sq7))
    {
        gameWon = true;
        winner = (sq1 == sq5 && sq5 == sq9) ? sq1 : sq3;
    }

    if (gameWon) 
    {
        // Output and file handling for winner
        cout << system("Color 72") << "\nCongratulations Player " << winner << ", you won!\n" << system("Color 70");    //changes color of text to green

        // Ask for another game
        char playAgain;
        cout << "Play again? (y/n): ";
        cin >> playAgain;
        if (playAgain == 'y' || playAgain == 'Y')
        {
            // Reset the board and continue the game in the main loop
            sq1 = '1'; sq2 = '2'; sq3 = '3';
            sq4 = '4'; sq5 = '5'; sq6 = '6';
            sq7 = '7'; sq8 = '8'; sq9 = '9';
            main();  // Call main again to restart the game
        }
        else
        {
            exit(0); // Exit if no replay
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

