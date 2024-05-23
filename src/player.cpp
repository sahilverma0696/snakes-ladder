#include "player.hpp"

string Player::getName() { return name; }

// TODO: potential [[no_discard]]
bool Player::updatePosition(int x) {
  // TODO: is x is less than max position, board values
  if (x >= 1) {
    position = x;
    return true;
  }
  else
   return false;
}

int Player::getPosition() { return position; }
