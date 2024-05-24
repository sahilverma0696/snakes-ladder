#pragma once
#include "basic.hpp"
#include "cell.hpp"
#include "board.hpp"

class GameSimulator {
private:
    int numPlayers;
    Board* board;
    std::vector<Player> players;

    int rollDice(); // Declaration of the rollDice function

public:
    GameSimulator(int numPlayers);
    // ~GameSimulator(); // Destructor to clean up memory

    void simulate();

};
