#include "board.hpp"
#include "basic.hpp"
#include "object.hpp"


Board::Board(int numCells, const std::vector<std::pair<int, int> > &snakes,
             const std::vector<std::pair<int, int> > &ladders)
    : numCells(numCells) {

    // cells.resize(numCells);
    for (int i = 0; i < numCells; ++i) {
        bool isWin = (i == numCells - 1);
        cells.push_back(Cell(i + 1, isWin, nullptr)); // Hard to find in unordered<pair<int,int>>
    }

    // Add snakes
    for (const auto& snake : snakes) {
        int start = snake.first;
        int end = snake.second;
        cout << "MAKING SNAKES" << endl;
        cout<<start<<"\t"<<end<<endl;
        if (start <= numCells && end <= numCells) {
            cells[start - 1].updateObject(new Snake(start, end)); // Add snake to start cell
            if(cells[start-1].getObject()->getType()==ObjectType::SNAKE)    cout<<"SNAKE"<<endl;
        }
    }

    // Add ladders
    for (const auto& ladder : ladders) {
        int start = ladder.first;
        int end = ladder.second;
        cout << "MAKING LADDER" << endl;
        cout<<start<<"\t"<<end<<endl;
        if (start <= numCells && end <= numCells) {
            cells[start - 1].updateObject(new Ladder(start, end)); // Add ladder to start cell
            if(cells[start-1].getObject()->getType()==ObjectType::LADDER)    cout<<"LADDER"<<endl;

        }
    }
}

int Board::getNumCells() { return numCells; }

Cell Board::getCell(int i) { return cells[i]; }

void Board::printBoard() const {
    for (int i = 0; i < numCells; ++i) {
        const Cell& cell = cells[i];
        std::cout << "Cell " << cell.getNumber() << ": ";
        if (cell.getObject() != nullptr) {
            if (cell.getObject()->getType() == ObjectType::SNAKE) {
                std::cout << "SNAKE";
            } else if (cell.getObject()->getType() == ObjectType::LADDER) {
                std::cout << "LADDER";
            }
        } else {
            std::cout << "EMPTY";
        }
        std::cout << std::endl;
    }
}


