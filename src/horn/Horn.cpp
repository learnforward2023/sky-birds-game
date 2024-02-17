//
// Created by Study Together on 2024/02/17.
//

#include "../common/Common.h"
#include "Horn.h"

/**
* Constructor of Horn class
* @return
*/
Horn::Horn(SDL_Renderer *screen) {
  _type = ENEMY_TYPE::HORN;
  _state = CHARACTER_STATE::FLYING;
  _hp = 100;
  _deviation = 0;

  LoadTextureViaState(screen);
}

/**
* Destructor of Horn class
 * @return
*/

Horn::~Horn() {
  Free();
}

/**
 * Handle attack randomly
 * @param SDL_Renderer* screen
 * @return void
 */
void Horn::HandleAttackRandomly(SDL_Renderer* screen) {
  int currentTicks = SDL_GetTicks();

  if (currentTicks % 10000 < 15) {
    _state = CHARACTER_STATE::ATTACKING;
    _bullets.push_back(new Bullet(BULLET_TYPE::E_PROIZE, _xPos + _widthFrame, _yPos, 4, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::E_PROIZE, _xPos + _widthFrame, _yPos, 2, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::E_NORMALIZE, _xPos + _widthFrame, _yPos, 0, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::E_PROIZE, _xPos + _widthFrame, _yPos, -2, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::E_PROIZE, _xPos + _widthFrame, _yPos, -4, screen));
  } else if (currentTicks % 8000 < 15) {
    _state = CHARACTER_STATE::ATTACKING;
    _bullets.push_back(new Bullet(BULLET_TYPE::E_PROIZE, _xPos + _widthFrame, _yPos, 2, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::E_NORMALIZE, _xPos + _widthFrame, _yPos, 0, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::E_PROIZE, _xPos + _widthFrame, _yPos, -2, screen));
  } else if (currentTicks % 6000 < 15) {
    _state = CHARACTER_STATE::ATTACKING;
    _bullets.push_back(new Bullet(BULLET_TYPE::E_PRO, _xPos + _widthFrame, _yPos, 2, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::E_NORMALIZE, _xPos + _widthFrame, _yPos, 0, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::E_PRO, _xPos + _widthFrame, _yPos, -2, screen));
  } else if (currentTicks % 4000 < 15) {
    _state = CHARACTER_STATE::ATTACKING;
    _bullets.push_back(new Bullet(BULLET_TYPE::E_NORMALIZE, _xPos + _widthFrame, _yPos, 2, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::E_NORMALIZE, _xPos + _widthFrame, _yPos, 0, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::E_NORMALIZE, _xPos + _widthFrame, _yPos, -2, screen));
  } else if (currentTicks % 2000 < 15) {
    _state = CHARACTER_STATE::ATTACKING;
    _bullets.push_back(new Bullet(BULLET_TYPE::E_NORMAL, _xPos + _widthFrame, _yPos, 2, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::E_PRO, _xPos + _widthFrame, _yPos, 0, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::E_NORMAL, _xPos + _widthFrame, _yPos, -2, screen));
  }
}
