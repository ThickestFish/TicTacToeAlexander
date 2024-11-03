#include "Game.h"
#include "TicTacToe.h"


// I could have had everything run from the header file but I figured I needed to separate the classes into headers and source files, otherwise what would be the point of having a header file?
// This helped me figure it out
// https://stackoverflow.com/questions/11884710/separate-classes-into-headers-and-source-files-in-c

bool TicTacToe::IsGameOver() const
{
    return m_turn == 9 || victory;
}
void TicTacToe::TakeTurn()
{
    m_turn++;
    if (m_turn % 2 == 0)
    {
        int action = 0;
        std::cout << "Player X's turn\nSelect a number on the grid\n";
        std::cin >> action;
        array[action - 1] = "X";
        DetectVictory();
    }
    else
    {
        int action = 0;
        std::cout << "Player O's turn\nSelect a number on the grid\n";
        std::cin >> action;
        array[action - 1] = "O";
        DetectVictory();
    }
}
void TicTacToe::Display() const
{

    for (int i = 0; i < 9; i++)
    {
        std::cout << array[i];
        if ((i + 1) % 3 == 0)
        {
            std::cout << "\n";
            if (i < 6)
            {
                std::cout << "---------\n";
            }
        }
        else
        {
            std::cout << " | ";
        }
    }
}
void TicTacToe::DetectVictory()
{
    // There's probably a better way to do this but this is the best I could come up with using the array to detect the winning player is likely bad optimization wooooo!
     /*
      * Where I got the idea for the Display function:
      * https://codereview.stackexchange.com/questions/268345/tic-tac-toe-in-c-with-classes
     */
    if (array[0] == array[1] && array[1] == array[2])
    {
        std::cout << "Player " << array[0] << " wins!\n";
        victory = true;
    }
    else if (array[3] == array[4] && array[4] == array[5])
    {
        std::cout << "Player " << array[3] << " wins!\n";
        victory = true;
    }
    else if (array[6] == array[7] && array[7] == array[8])
    {
        std::cout << "Player " << array[6] << " wins!\n";
        victory = true;
    }
    else if (array[0] == array[3] && array[3] == array[6])
    {
        std::cout << "Player " << array[0] << " wins!\n";
        victory = true;
    }
    else if (array[1] == array[4] && array[4] == array[7])
    {
        std::cout << "Player " << array[1] << " wins!\n";
        victory = true;
    }
    else if (array[2] == array[5] && array[5] == array[8])
    {
        std::cout << "Player " << array[2] << " wins!\n";
        victory = true;
    }
    else if (array[0] == array[4] && array[4] == array[8])
    {
        std::cout << "Player " << array[0] << " wins!\n";
        victory = true;
    }
    else if (array[2] == array[4] && array[4] == array[6])
    {
        std::cout << "Player " << array[2] << " wins!\n";
        victory = true;
    }
    else
    {
        if (m_turn == 9)
        {
            std::cout << "It's a tie!\n";
        }
    }
}