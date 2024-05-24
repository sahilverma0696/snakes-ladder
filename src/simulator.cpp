#include "simulator.hpp"
#include "object.hpp"
#include "player.hpp"
#include <__config>

GameSimulator::GameSimulator(int numPlayers) : numPlayers(numPlayers) {
  // Initialize the board with appropriate parameters
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
    board = new Board(100, snakes, ladders);
    
    // Initialize players
    for (int i = 0; i < numPlayers; ++i) {
        players.push_back(Player("Player " + std::to_string(i+1))); // naming them in number
    }
    for (auto x : players) {
      cout<<x.getName()<<"\t"<<x.getPosition()<<endl;
    }

    // board->printBoard();
}

// GameSimulator::~GameSimulator() {
//     delete board;
// }

void GameSimulator::simulate() {


    cout<<"STARTING GAME"<<endl;
    long long round = 0;
    while (true) {
        std::cout << "Round " << round + 1 << ":" << std::endl;
        for (int i = 0; i < numPlayers; ++i) {
            int roll = rollDice(); //TODO: Implement rollDice function
            Player& currentPlayer = players[i];
            int currentPosition = currentPlayer.getPosition();
            int newPosition = currentPosition + roll;

            cout << "New Roll position " << newPosition << endl;
            
            if (newPosition < board->getNumCells()) {
              Object *currentObj = board->getCell(newPosition).getObject();
              Player *beforePlayer = board->getCell(newPosition).getPlayer();
              if (currentObj->getType() == ObjectType::SNAKE) {
                currentPlayer.updatePosition(currentObj->getEnd());
              } else if (currentObj->getType() == ObjectType::LADDER) {
                currentPlayer.updatePosition(currentObj->getEnd());
              } else if (beforePlayer != nullptr) {
                beforePlayer->updatePosition(1); // move existing player to start
                board->getCell(newPosition).updatePlayer(&currentPlayer);
                currentPlayer.updatePosition(newPosition);
              } else {
                currentPlayer.updatePosition(newPosition);
                board->getCell(newPosition).updatePlayer(&currentPlayer);
                currentPlayer.updatePosition(newPosition);
              }

            } else {
              cout<<"END HERE";
                // Player reached the end of the board
                std::cout << currentPlayer.getName() << " reached the end of the board!" << std::endl;
                std::cout << currentPlayer.getName() << " wins the game!" << std::endl;
                return; // End the simulation
            }

            cout<< currentPlayer.getName()<<"\t"<<currentPlayer.getPosition()<<endl;
        }
        
        // Print the current state of the board after each round
        // board->printBoard();

        round++;
    }
}

int GameSimulator::rollDice() {
    // Seed the random number generator
    srand(time(nullptr));
    
    // Roll a six-sided die (returns a number between 1 and 6)
    return rand() % 6 + 1;
}
