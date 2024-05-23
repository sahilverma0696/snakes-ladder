#include "cell.hpp"
#include "player.hpp"

Player* Cell::getPlayer() {
    if(state == CellState::FULL)
        return currentPlayer;
    else
        return nullptr;
}

void Cell::updatePlayer(Player *p) {
    currentPlayer = p;
    state = CellState::FULL;
}

CellState Cell::getCellState() { return state; }

void Cell::updateCellState(CellState newState) { state = newState; }

int Cell::getNumber() const { return number; }

void Cell::updateObject(Object *obj) { this->obj = obj; }

Object* Cell::getObject() const {return obj;}





