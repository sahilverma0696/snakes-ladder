#include "simulator.hpp"
#include "basic.hpp"
#include "object.hpp"
#include "player.hpp"
#include <__config>
#include "json_parse.cpp"

GameSimulator::GameSimulator() {
  srand(time(nullptr));

  config.filename ="./config/config.json";

    // Create vectors for snakes and ladders
    vector<pair<int, int> > snakes;
    vector<pair<int, int> > ladders;

    readConfig(config);
    numCells = config.numCells;
    board = new Board(numCells, config.snakes, config.ladders);
    
    // Initialize players
    for (int i = 0; i < config.numPlayers; ++i) {
        players.push_back(Player("Player " + to_string(i+1))); //TODO:naming update from JSON remaining
    }
    for (auto x : players) {
      cout<<x.getName()<<"\t"<<x.getPosition()<<endl;
    }

}

GameSimulator::~GameSimulator() {
    delete board;
}

// FEATURE **: if one wishes to provide manual values for dice, default param can be taken here 
void GameSimulator::simulate(int manualDice) {


    cout<<"STARTING GAME"<<endl;
    long long round = 0;
    while (true) {
      cout << "Round " << round + 1 << ":\n" << endl;
        for (int i = 0; i < config.numPlayers; ++i) {
          int roll = manualDice ==0 ?rollDice():manualDice; // FEATURE **: and can override here
          Player &currentPlayer = players[i];
            int currentPosition = currentPlayer.getPosition();
            int newPosition = currentPosition + roll;


            cout<<"TERM for "<<currentPlayer.getName()<<"having current position as "<<currentPosition +1 <<" having dice value "<<roll<<endl;

            if (newPosition < board->getNumCells()) {
              Object *currentObj = board->getCell(newPosition).getObject();
              Player *beforePlayer = board->getCell(newPosition).getPlayer();

              if (currentObj != nullptr && currentObj->getType() == ObjectType::SNAKE) {
                cout << "SNAKE Encounter for " << currentPlayer.getName()
                     << endl;
                cout<<"SNAKE HAVING TAIL AT "<< currentObj->getEnd()<<endl;
                currentPlayer.updatePosition(currentObj->getEnd());
              }

              else if (currentObj != nullptr && currentObj->getType() == ObjectType::LADDER) {
                cout << "LADDER Encounter for " << currentPlayer.getName()
                     << endl;
                cout<<"LADDER HAVING HEAD AT "<< currentObj->getEnd()<<endl;
                currentPlayer.updatePosition(currentObj->getEnd());
              }

              else if (currentObj != nullptr && currentObj->getType() == ObjectType::CROC) {
                cout << "CROC Encounter for " << currentPlayer.getName()
                     << endl;
                cout<<"CROC HAVING HEAD AT "<< currentObj->getEnd()<<endl;
                currentPlayer.updatePosition(currentObj->getEnd());
              }

              else if (beforePlayer != nullptr) {
                cout<<"EXISTING player on this position for "<<beforePlayer->getName()<<endl;
                beforePlayer->updatePosition(1); // move existing player to start
                board->getCell(newPosition).updatePlayer(&currentPlayer);
                currentPlayer.updatePosition(newPosition);
              }

              else {
                currentPlayer.updatePosition(newPosition);
                board->getCell(newPosition).updatePlayer(&currentPlayer);
                currentPlayer.updatePosition(newPosition);
              }

            } else if (newPosition == board->getNumCells()) {
                // Player reached the end of the board
                cout << currentPlayer.getName() << " reached the end of the board!" << endl;
                cout << currentPlayer.getName() << " wins the game!" << endl;
                return;
            }

            cout<<"UPDATED POSITION FOR "<< currentPlayer.getName()<<" IS "<<currentPlayer.getPosition()<<endl;
        }
        
        // Print the current state of the board after each round
        // board->printBoard();

        round++;
        if (round == config.maxRounds) {
          cout << "KILL SWITCH TRIGGERED, PLAYING FOR TOO LONG, GO STUDY"
               << endl;
          break;
        }
    }
}

int GameSimulator::rollDice() {
  
    int total = 0;
    for (int i = 0; i < config.numDice; ++i) {
        // Roll each die
        int die = rand() % 6 + 1;
        total += die;
    }


    switch (config.dicePolicy) {
    case DicePolicy::SUM:
      return total;
            // return total;
        case DicePolicy::MIN: {
            int min = 6; 
            for (int i = 0; i < config.numDice; ++i) {
                int die = rand() % 6 + 1;
                if (die < min) {
                    min = die;
                }
            }
            
            return min;
        }
        case DicePolicy::MAX: {
            int max = 1;
            for (int i = 0; i < config.numDice; ++i) {
                int die = rand() % 6 + 1;
                if (die > max) {
                    max = die;
                }
            }
            
            return max;
        }
        default:
          // return total;
          return total;
        }
}
