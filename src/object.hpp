#pragma once
#include "basic.hpp"

// base file for all the objects which can be placed on the board
// not players, e.g., snake, ladder, croc, mine

enum class ObjectType { EMPTY, SNAKE, LADDER, CROC, MINE };

class Object {
  int start;
  int end;

public:
  
    Object(int start =1,int end =1):start(start),end(end){};

    int getStart() const;

    int getEnd() const;

    virtual ObjectType getType() const = 0; // Hate this guy, but helped a lot in simulation

    //TODO: shall make a isStable: allows to register in cell only if this is a valid obj ( start, stop valid values)
};

class Snake : public Object {
  public:
    Snake(int start, int end) : Object(start, end) {}
    ObjectType getType() const override {
        return ObjectType::SNAKE;
    }
};

class Ladder : public Object {
public:
  Ladder(int start, int end) : Object(start, end) {}
  ObjectType getType() const override {
        return ObjectType::LADDER;
    }
};

//TODO: set the values to 5 less for croc
class Croc : public Object {
  int power;
  int start,end;

  void __updateEnd__() { end = start - power; }
  
  public:
    Croc(int start) : Object(start) {
      power = 5;
      __updateEnd__();
    }
  ObjectType getType() const override {
        return ObjectType::CROC;
    }
};

// TODO: handle this gut too
class Mine : public Object {
  int count;
  public:
    Mine(int start = 1, int end = 1) : Object(start, end) { count = 2; }
  ObjectType getType() const override {
        return ObjectType::MINE;
    }
};