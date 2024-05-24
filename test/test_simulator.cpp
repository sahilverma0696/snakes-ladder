#include "../src/basic.hpp"
#include "../src/cell.hpp"
#include "../src/board.hpp"
#include "../src/simulator.hpp"

int main() {
    GameSimulator* simulator = new GameSimulator();

    // Simulate the game
    simulator->simulate();

    return 0;
}
