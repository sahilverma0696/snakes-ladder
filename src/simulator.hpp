#pragma once
#include "basic.hpp"
#include "cell.hpp"
#include "board.hpp"

class GameSimulator {
private:
  GameConfig config;
  int numPlayers;
  int numCells;

    Board* board;
    vector<Player> players;

    int rollDice(); // Declaration of the rollDice function

public:
    GameSimulator();
    ~GameSimulator(); // Destructor to clean up memory

    void simulate(int manualDice=0);

};
