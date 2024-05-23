#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <string.h>
#include <utility>


using namespace std;

// Forward declarations for structs and classes used within the game
// class Player;
#include "player.hpp"
// class Object;
#include "object.hpp"
// class Cell;
// #include "cell.hpp"
class Board;
class Simulator;

// this is the cell which contains a cell info
enum class CellState { EMPTY = 0, FULL };



// class Snake;
// #include "object.hpp"
// // class Ladder;
// #include "object.hpp"
// // class Croc;
// #include "object.hpp"
// // class Mine;
// #include "object.hpp"
