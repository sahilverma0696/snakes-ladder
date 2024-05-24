#include "../src/basic.hpp"
#include "../src/cell.hpp"

// this is to test the cell layer and below 
void testCell() {
    std::cout << "Creating cells..." << std::endl;

    std::vector<Cell> cells;
    for (int i = 1; i <= 10; ++i) {
        if (i % 2 == 0) {
            Object* objPtr = new Snake(i, i + 1); // Example Snake object with start and end positions
            cells.emplace_back(i, false, objPtr); // Create cell with object
        } else {
            cells.emplace_back(i, false, nullptr); // Create cell without object
        }
    }

    std::cout << "Verifying cell states..." << std::endl;

    for (auto& cell : cells) {
        std::cout << "Cell " << cell.getNumber() << " state: ";
        if (cell.getCellState() == CellState::FULL) {
            std::cout << "FULL" << std::endl;
        } else {
            std::cout << "EMPTY" << std::endl;
        }
        std::cout << "Current player: ";
        Player* currentPlayer = cell.getPlayer();
        if (currentPlayer != nullptr) {
            std::cout << currentPlayer->getName() << std::endl;
        } else {
            std::cout << "None" << std::endl;
        }
    }

    std::cout << "Updating player and cell states..." << std::endl;

    // Update player and cell states
    Player player("Alice");
    cells[0].updatePlayer(&player);
    cells[1].updateCellState(CellState::FULL);

    std::cout << "Verifying updated cell states..." << std::endl;

    for (auto& cell : cells) {
        std::cout << "Cell " << cell.getNumber() << " state: ";
        if (cell.getCellState() == CellState::FULL) {
            std::cout << "FULL" << std::endl;
        } else {
            std::cout << "EMPTY" << std::endl;
        }
        std::cout << "Current player: ";
        Player* currentPlayer = cell.getPlayer();
        if (currentPlayer != nullptr) {
            std::cout << currentPlayer->getName() << std::endl;
        } else {
            std::cout << "None" << std::endl;
        }
    }
}

int main() {
    testCell();
    return 0;
}