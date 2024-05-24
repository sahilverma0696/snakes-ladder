#include <iostream>
#include <random>
#include <unordered_set>
#include "../src/basic.hpp"
#include "../src/cell.hpp"
#include "../src/board.hpp"

void testBoard() {

  // taking assumptions that
    // Initialize random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100); // Range from 1 to 100 for cell numbers

    // Create vectors for snakes and ladders
    std::vector<std::pair<int, int> > snakes;
    std::vector<std::pair<int, int> > ladders;

    // Generate 10 unique random positions for snakes
    while (snakes.size() < 10) {
    int start = dis(gen);
    int end = dis(gen);

    // Ensure end is less than start and larger than 0
    if (end < start && end >= 1) {
        snakes.push_back({start, end});
    }
    }


    // Generate 10 unique random positions for ladders
    while (snakes.size() < 10) {
    int start = dis(gen);
    int end = dis(gen);

    // Ensure end is less than start and larger than 0
    if (start < end && end < 100) {
        snakes.push_back({start, end});
    }
    }


    // Create the board
    // really love this feature in c++, handled in place of struct as well
    Board board(100, snakes, ladders);

    board.printBoard();
}

int main() {
    testBoard();
    return 0;
}
