#pragma once
#include "basic.hpp"

class Player {
private:
  string name;
  int    position;

public:
  Player(string name,int position = 1):name(name),position(position){}
  string getName();

  bool updatePosition(int x);
  int getPosition();
};
