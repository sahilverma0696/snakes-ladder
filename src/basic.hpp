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

// this helps in checking out cell state faster
enum class CellState { EMPTY = 0, FULL };

// the functional requirement for dicing policy
enum class DicePolicy {
    SUM,
    MIN,
    MAX
};

// for expansion of GameConfig add values here and in /config/config.json
struct GameConfig {
    std::string filename;
    std::vector<std::pair<int, int> > snakes;
    std::vector<std::pair<int, int> > ladders;
    std::vector<int> crocs;
    int numCells;
    int numPlayers;
    int maxRounds;
    int numDice;
    DicePolicy dicePolicy;
};
