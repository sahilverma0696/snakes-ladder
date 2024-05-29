#include "json.hpp"
#include "basic.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using json = nlohmann::json;

// This is the function, in this we can add new constraints to json, and read it here, add new attribute to the struct GameConfig
void readConfig(GameConfig& configObj) {
    ifstream file(configObj.filename);
    json config;
    file >> config;

    for (const auto& snake : config["snakes"]) {
        configObj.snakes.push_back(make_pair(snake["head"], snake["tail"]));
    }

    for (const auto& ladder : config["ladders"]) {
        configObj.ladders.push_back(make_pair(ladder["tail"], ladder["head"]));
    }

    for (const auto& croc : config["crocs"]) {
        configObj.crocs.push_back(croc);
    }

    configObj.numCells = config["numCells"];

    configObj.numPlayers = config["numPlayers"];

    configObj.maxRounds = config["maxRounds"];

    configObj.numDice = config["numDice"];

    
    if (config["dicePolicy"] == "SUM") {
      configObj.dicePolicy = DicePolicy::SUM;
    } else if (config["dicePolicy"] == "MIN") {
      configObj.dicePolicy = DicePolicy::MIN;
    } else {
      configObj.dicePolicy = DicePolicy::MAX;
    }
}
