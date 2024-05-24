#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <string.h>
#include <utility>
#include <cstdlib>
#include <ctime>


using namespace std;

#include "player.hpp"
#include "object.hpp"

class Board;
class Simulator;

enum class CellState { EMPTY = 0, FULL };

enum class DicePolicy {
    SUM,
    MIN,
    MAX
};


struct GameConfig {
    std::string filename;
    std::vector<std::pair<int, int> > snakes;
    std::vector<std::pair<int, int> > ladders;
    int numCells;
    int numPlayers;
    int maxRounds;
    int numDice;
    DicePolicy dicePolicy;
};

// class Snake;
// #include "object.hpp"
// // class Ladder;
// #include "object.hpp"
// // class Croc;
// #include "object.hpp"
// // class Mine;
// #include "object.hpp"
