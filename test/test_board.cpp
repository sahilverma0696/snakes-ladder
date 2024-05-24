#include <iostream>
#include <random>
#include <unordered_set>
#include "../src/basic.hpp"
#include "../src/cell.hpp"
#include "../src/board.hpp"

void testBoard() {
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
        if (start != end) {
            snakes.push_back( {start, end} );
        }
    }
    for (auto p : snakes) {
      cout<<p.first<<"\t"<<p.second<<endl;
    }

    // Generate 10 unique random positions for ladders
    while (ladders.size() < 10) {
        int start = dis(gen);
        int end = dis(gen);
        if (start != end) {
            ladders.push_back( {start, end} );
        }
    }
    for (auto p : ladders) {
      cout<<p.first<<"\t"<<p.second<<endl;
    }

    // Create the board
    Board board(100, snakes, ladders);

    board.printBoard();
}

int main() {
    testBoard();
    return 0;
}
