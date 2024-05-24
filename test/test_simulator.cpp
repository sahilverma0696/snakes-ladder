#include "../src/basic.hpp"
#include "../src/cell.hpp"
#include "../src/board.hpp"
#include "../src/simulator.hpp"

// Kind of main file, also it uses the config and top layer features included in the game
int main() {
    GameSimulator* simulator = new GameSimulator();

    // Simulate the game
    simulator->simulate();

    return 0;
}
