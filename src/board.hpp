#pragma once
#include "basic.hpp"
#include "cell.hpp"

class Board {
private:
    const int numCells;
    vector<Cell> cells;

public:
    Board(int numCells, const vector<pair<int, int> >& snakes, const vector<pair<int, int> >& ladders, const vector<int> &crocs);

    int getNumCells();

    Cell getCell(int i);

    void printBoard();
};

