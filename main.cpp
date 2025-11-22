/*Ryan Puska        Connect Four        11/19
This program uses a class to create a connect four game. It
has the declarations in board.h, functionality in board.cpp,
and calls in main.cpp.*/
#include <iostream>
#include "board.h"

using namespace std;

int main()
{
    //create run object
    Board run;
    //call functions
    run.displayBoard();
    run.choosePlace();
    return 0;
}
