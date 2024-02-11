//
// Created by Study Together on 2024/02/11.
//

#include "Player.h"

Player::Player() {
  _xPos = 0;
  _yPos = 0;
  _rect = {0, 0, 0, 0};
  _texture = nullptr;
}

Player::~Player() {
  Free();
}
