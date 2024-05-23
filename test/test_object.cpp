#include "../src/basic.hpp"
#include <iostream>
#include <cassert>

void testObject() {
    // Test case 1: Object start and end positions
    std::cout << "Test case 1: Object start and end positions" << std::endl;
    Object obj(3, 7);
    std::cout << "Start position: " << obj.getStart() << ", Expected: 3" << std::endl;
    std::cout << "End position: " << obj.getEnd() << ", Expected: 7" << std::endl;
    assert(obj.getStart() == 3);
    assert(obj.getEnd() == 7);

    // Test case 2: Snake class
    std::cout << "Test case 2: Snake class" << std::endl;
    Snake snake(9,3);
    std::cout << "Start position: " << snake.getStart() << ", Expected: 9" << std::endl;
    std::cout << "End position: " << snake.getEnd() << ", Expected: 3" << std::endl;
    assert(snake.getStart() == 9); // Default start position
    assert(snake.getEnd() == 3);   // Default end position

    // Test case 3: Ladder class
    std::cout << "Test case 3: Ladder class" << std::endl;
    Ladder ladder(2, 6);
    std::cout << "Start position: " << ladder.getStart() << ", Expected: 2" << std::endl;
    std::cout << "End position: " << ladder.getEnd() << ", Expected: 6" << std::endl;
    assert(ladder.getStart() == 2);
    assert(ladder.getEnd() == 6);

    // // Test case 4: Croc class
    // std::cout << "Test case 4: Croc class" << std::endl;
    // Croc croc(9);
    // std::cout << "Start position: " << croc.getStart() << ", Expected: 9" << std::endl;
    // std::cout << "End position: " << croc.getEnd() << ", Expected: 4" << std::endl;
    // assert(croc.getStart() == 9);
    // assert(croc.getEnd() == 4);

    // Test case 5: Mine class
    std::cout << "Test case 5: Mine class" << std::endl;
    Mine mine(8, 12);
    std::cout << "Start position: " << mine.getStart() << ", Expected: 8" << std::endl;
    std::cout << "End position: " << mine.getEnd() << ", Expected: 12" << std::endl;
    assert(mine.getStart() == 8);
    assert(mine.getEnd() == 12);

    std::cout << "All test cases passed successfully." << std::endl;
}

int main() {
    testObject();
    return 0;
}
