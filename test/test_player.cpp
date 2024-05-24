#include "../src/basic.hpp"
#include <iostream>
#include <cassert>


// bottom layer player test cases
void testPlayer() {
    Player player("Alice",1);

    // Test case 1: Set and get player name
    cout << "Test case 1: Set and get player name" << endl;
    assert(player.getName() == "Alice");

    // Test case 2: Set and get player position
    cout << "Test case 2: Set and get player position" << endl;
    assert(player.getPosition() == 1); // Default position should be 1

    // Test case 3: Set valid position
    cout << "Test case 3: Set valid position" << endl;
    assert(player.updatePosition(5) == true);
    assert(player.getPosition() == 5);

    // Test case 4: Set invalid position (negative)
    cout << "Test case 4: Set invalid position (negative)" << endl;
    assert(player.updatePosition(-3) == false); // Position cannot be negative
    assert(player.getPosition() == 5); // Position should remain unchanged

    cout << "All test cases passed successfully." << endl;
}

int main() {
    testPlayer();
    return 0;
}
