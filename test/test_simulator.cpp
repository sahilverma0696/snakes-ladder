#include "../src/basic.hpp"
#include "../src/cell.hpp"
#include "../src/board.hpp"
#include "../src/simulator.hpp"

int main() {
    // Create a game simulator with 4 players
    GameSimulator simulator(4);

    // Simulate the game
    simulator.simulate();

    return 0;
}
