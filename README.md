# snakes-ladder

Please read /docs/design to understand the assumptions taken and class tree structure 

# note
- This program uses random generation of roll dice, which can lead to almost infinite loop, so there's a kill switch by number of rounds
- Do not change anything in /src/json.hpp it's open-source lib header

## usage 
- look for makefile for specific test cases running 

- run `make test_all` for all the values being played

## Modularity

- This code is written on layered architecture, allowing the developer to config and update the layers and classes to their needs
- Same reason there is not direct `main.cpp` is not provided, please feel free to make one taking inspiration from /test classes, if you've a different test case in mind


## Functional requirements
    - Number of players: N      [DONE]
    - Board Size: BS (BS x BS)  [DONE]
    - Number of Snakes: S       [DONE]
    - Number of Ladders: L      [DONE]
    - Number of Dies: D         [DONE]
    - Movement Strategy: MS     [DONE]
    - Sample input to populate  [DONE] 
    - Snake bites, down         [DONE]
    - Ladder, up                [DONE]
    - Player overkill           [DONE]
## Optional 
    - Random board generate valid   [DONE]
    - Test cases                    [DONE]    
    - Special Objects               [PlaceHolder & Foundation implemented]  
    - Logging                       [DONE]
    - Driver (Simulator)            [DONE]
    - Die Value & Round Robin       [DONE]
    - Configurable                  [DONE]


## PS
    - This code will be having spelling mistakes, please try to overlook them, I'm a developer
