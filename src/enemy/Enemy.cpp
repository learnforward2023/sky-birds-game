//
// Created by Study Together on 2024/02/17.
//

#include "Enemy.h"

/**
* Enemy constructor
* @return
*/
Enemy::Enemy() {
  _type = ENEMY_TYPE::ALIEN;
  _hp = 0;
  _state = CHARACTER_STATE::FLYING;
  _deviation = 0;
  _xPos = -1;
}

/**
 * Enemy destructor
 * @return
 */
Enemy::~Enemy() {
  Free();
}

/**
 * Handle move of enemy
 * @return void
 */
void Enemy::HandleMove() {
  if (_inputType._up && _yPos < 0) {
    _inputType._up = false;
  }

  if (_inputType._down && _yPos > GAME_SCREEN_HEIGHT - _heightFrame) {
    _inputType._down = false;
  }

  if (_inputType._left && _xPos < 0) {
    _inputType._left = false;
  }

  if (_inputType._right && _xPos > GAME_SCREEN_WIDTH - _widthFrame) {
    _inputType._right = false;
  }

  if (_inputType._up) {
    _yPos += _deviation;
  }

  if (_inputType._down) {
    _yPos += _deviation;
  }

  if (_inputType._left) {
    _xPos += _speed;
  }

  if (_inputType._right) {
    _xPos += _speed;
  }
}

/**
 * Load the texture of the enemy based on the state of the enemy.
 * @param SDL_Renderer* screen
 * @return void
 */
void Enemy::LoadTextureViaState(SDL_Renderer *screen) {
  if (_state == FLYING) {
    switch (_type) {
      case ENEMY_TYPE::DARK:
        LoadTexture("/enemy/dark.png", screen);
        break;
      case ENEMY_TYPE::ALIEN:
        LoadTexture("/enemy/alien.png", screen);
        break;
      case ENEMY_TYPE::HORN:
        LoadTexture("/enemy/horn.png", screen);
        break;
      case ENEMY_TYPE::EYE:
        LoadTexture("/enemy/eye.png", screen);
        break;
      default:
        break;
    }
  } else if (_state == ATTACKING) {
    switch (_type) {
      case ENEMY_TYPE::DARK:
        LoadTexture("/enemy/dark-attacking.png", screen);
        break;
      case ENEMY_TYPE::ALIEN:
        LoadTexture("/enemy/alien-attacking.png", screen);
        break;
      case ENEMY_TYPE::HORN:
        LoadTexture("/enemy/horn-attacking.png", screen);
        break;
      case ENEMY_TYPE::EYE:
        LoadTexture("/enemy/eye-attacking.png", screen);
        break;
      default:
        break;
    }
  }

  SetFrameClip();
}

/**
 * Render enemy
 * @param screen
 */
void Enemy::Render(SDL_Renderer *screen) {
  if (_currentFrame >= 10) {
    _currentFrame = 0;

    if (_state == CHARACTER_STATE::ATTACKING) {
      _state = CHARACTER_STATE::FLYING;
    }
  }

  LoadTextureViaState(screen);
  HandleMove();

  SDL_Rect* currentClip = &_frameClip[_currentFrame];
  SDL_Rect renderQuad = { _xPos, _yPos, _widthFrame, _heightFrame };
  Base::Render(screen, currentClip, &renderQuad);

  _currentFrame++;
}

/**
 * Handle random move of enemy
 * @param screen
 */
void Enemy::HandleRandomMove(SDL_Renderer *screen) {
  int currentTime = SDL_GetTicks();

  if (_xPos == -1) {
    _inputType._left = true;
    _speed = -3;
    _xPos = GAME_SCREEN_WIDTH;
    _yPos = rand() % GAME_SCREEN_HEIGHT - 100;
    _deviation = 0;
  }
  if (currentTime % 2000 < 20) {
    int randomMove = rand() % 4;

    switch (randomMove) {
      case 0:
        _inputType._left = true;
        _inputType._right = false;
        _speed = -2;
        if (_yPos > GAME_SCREEN_HEIGHT - _heightFrame - 80) {
          _deviation = -2;
          _inputType._up = true;
          _inputType._down = false;
        } else if (_yPos < 30) {
          _deviation = 2;
          _inputType._up = false;
          _inputType._down = true;
        }

        break;
      case 1:
        _inputType._left = false;
        _inputType._right = true;
        _speed = 2;
        if (_yPos > GAME_SCREEN_HEIGHT - _heightFrame - 80) {
          _deviation = -2;
          _inputType._up = true;
          _inputType._down = false;
        } else if (_yPos < 30) {
          _deviation = 2;
          _inputType._up = false;
          _inputType._down = true;
        }
        break;
      case 2:
        _inputType._up = true;
        _inputType._down = false;
        _deviation = -2;
        if (_yPos < 30) {
          _deviation = 2;
          _inputType._down = true;
          _inputType._up = false;
        }
        break;
      case 3:
        _inputType._up = false;
        _inputType._down = true;
        _deviation = 2;
        if (_yPos > GAME_SCREEN_HEIGHT - _heightFrame - 80) {
          _deviation = -2;
          _inputType._up = false;
          _inputType._down = true;
        }
        break;
      default:
        break;
    }
  }

  Render(screen);
}
