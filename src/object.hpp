#pragma once
#include "basic.hpp"

// base file for all the objects which can be placed on the board
// not players, e.g., snake, ladder, croc, mine

class Object {
  int start;
  int end;

public:
  
    Object(int start =1,int end =1):start(start),end(end){};

    int getStart() const;
    // void setStart(int newStart);

    int getEnd() const;
    // void setEnd(int newEnd);

    //TODO: shall make a isStable: allows to register in cell only if this is a valid obj ( start, stop valid values)
};

class Snake : public Object {
  public:
  Snake(int start, int end) : Object(start, end) {}
};

class Ladder : public Object {
public:
  Ladder(int start, int end) : Object(start, end) {}
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
};

// TODO: handle this gut too
class Mine : public Object {
  int count;
  public:
    Mine(int start = 1, int end = 1) : Object(start, end) { count = 2;}
};