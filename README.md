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

## PS
    - This code will be having spelling mistakes, please try to overlook them, I'm a developer
