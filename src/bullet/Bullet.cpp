//
// Created by Study Together on 2024/02/16.
//

#include "Bullet.h"

/**
 * Constructor of Bullet class to initialize the properties of the bullet.
 * @return void
 */
Bullet::Bullet() {
  _widthFrame = 0;
  _heightFrame = 0;
}

/**
 * Destructor of Bullet class to free the memory of the bullet after the game is over.
 * @return void
 */
Bullet::~Bullet() {
  Free();
}
