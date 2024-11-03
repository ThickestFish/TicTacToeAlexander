#pragma once

#include "Game.h"
#include <iostream>
#include <string>

class TicTacToe : public Game
{
private:
    int m_turn = 0;
    bool victory = false;
    std::string m_action = " ";
    std::string array[9] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
public:
    
    virtual void DetectVictory();
    virtual bool IsGameOver() const;
    virtual void TakeTurn();
    virtual void Display() const;
};