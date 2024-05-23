#pragma once
#include "basic.hpp"
#include "object.hpp"

class Cell {

private:
  int number;
  Player* currentPlayer;
  bool isWin;
  Object* obj;
  CellState state;

public:
  Cell(int number, bool isWin, Object* obj)
      : number(number), isWin(isWin), obj(obj) {
    currentPlayer = nullptr;
  };
  Player* getPlayer();
  void updatePlayer(Player* p);

  CellState getCellState();
  void updateCellState(CellState newState);

  int getNumber() const;

  void updateObject(Object *obj);

  Object* getObject() const;
};