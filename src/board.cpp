#include "board.hpp"
#include "basic.hpp"
#include "object.hpp"


Board::Board(int numCells, const vector<pair<int, int> > &snakes,
             const vector<pair<int, int> > &ladders, const vector<int> &crocs)
    : numCells(numCells) {

    // cells.resize(numCells); // need special obj initialization
    for (int i = 0; i < numCells; ++i) {
        bool isWin = (i == numCells - 1);
        cells.push_back(Cell(i, isWin, nullptr)); // Hard to find in unordered<pair<int,int>>
    }

    // Add snakes
    for (const auto& snake : snakes) {
        int start = snake.first;
        int end = snake.second;
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
        cout<<start<<"\t"<<end<<endl;
        if (start <= numCells && end <= numCells) {
            cells[start - 1].updateObject(new Ladder(start, end)); // Add ladder to start cell
            if(cells[start-1].getObject()->getType()==ObjectType::LADDER)    cout<<"LADDER"<<endl;

        }
    }

    // Add crocs
    for (const auto& croc : crocs) {
        int start = croc;
        cout<<start<<"\t"<<endl;
        if (start >= 6 && start <= numCells) {
            cells[start - 1].updateObject(new Croc(start)); // Add ladder to start cell
            if(cells[start-1].getObject()->getType()==ObjectType::CROC)    cout<<"CROC"<<endl;

        }
    }

    // Printing the ready board
    printBoard();
}

int Board::getNumCells() { return numCells; }

Cell Board::getCell(int i) { return cells[i]; }

void Board::printBoard() {

  cout<<"FINAL CONFIG OF BOARD"<<endl;
    for (int i = 0; i < numCells; ++i) {
        const Cell& cell = cells[i];
        cout << "Cell " << cell.getNumber() << ": ";
        if (cell.getObject() != nullptr) {
            if (cell.getObject()->getType() == ObjectType::SNAKE) {
                cout << "SNAKE STARTS : " << cell.getObject()->getStart()<<" ENDS AT "<< cell.getObject()->getEnd() << endl;
            } else if (cell.getObject()->getType() == ObjectType::LADDER) {
                cout << "LADDER";
            }
        } else {
            cout << "EMPTY";
        }
        cout << endl;
    }
    cout<<endl;
}


