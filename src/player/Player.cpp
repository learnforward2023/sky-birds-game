//
// Created by Study Together on 2024/02/11.
//

#include "Player.h"
#include "../sound_effect/SoundEffect.h"
#include "../bullet/Bullet.h"

/**
 * Constructor of Player class to initialize the properties of the player.
 * @return void
 */
Player::Player() {
  _widthFrame = 0;
  _heightFrame = 0;
  _currentFrame = 0;
}

/**
 * Constructor of Player class to initialize the properties of the player and load the texture of the player.
 * @param SDL_Renderer* screen
 * @return void
 */
Player::Player(SDL_Renderer* screen) {
  _widthFrame = 0;
  _heightFrame = 0;
  _currentFrame = 0;
  _speed = 10;
  _level = 1;

  LoadTexture("/player/flying.png", screen);
  SetFrameClip();
}

/**
 * Destructor of Player class to free the memory of the player after the game is over.
 * @return void
 */
Player::~Player() {
  Free();
}

/**
 * Render the player on the screen.
 * @param SDL_Renderer* screen
 * @return void
 */
void Player::Render(SDL_Renderer* screen) {
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
  Bullet::RenderBullets(screen, _bullets);
  Base::Render(screen, currentClip, &renderQuad);

  _currentFrame++;
}

/**
 * Set the frame clip of the player,
 * @return void
 */
void Player::HandleInputAction(SDL_Event event, SDL_Renderer* screen) {
  if (event.type == SDL_KEYDOWN) {
    HandleKeyDown(event, screen);
  } else if (event.type == SDL_KEYUP) {
    HandleKeyUp(event);
  }
}

/**
 * Handle the key down event of the player.
 * @param SDL_Event event
 * @return void
 */
void Player::HandleKeyDown(SDL_Event event, SDL_Renderer* screen) {
  if (event.type == SDL_KEYDOWN) {
    switch (event.key.keysym.sym) {
      case SDLK_UP:
        _inputType._up = true;
        break;
      case SDLK_DOWN:
        _inputType._down = true;
        break;
      case SDLK_LEFT:
        _inputType._left = true;
        break;
      case SDLK_RIGHT:
        _inputType._right = true;
        break;
      case SDLK_SPACE:
        HandleAttack(screen);
        break;
      default:
        break;
    }
  }
}

/**
 * Handle the key up event of the player.
 * @param SDL_Event event
 * @return void
 */
void Player::HandleKeyUp(SDL_Event event) {
  if (event.type == SDL_KEYUP) {
    switch (event.key.keysym.sym) {
      case SDLK_UP:
        _inputType._up = false;
        break;
      case SDLK_DOWN:
        _inputType._down = false;
        break;
      case SDLK_LEFT:
        _inputType._left = false;
        break;
      case SDLK_RIGHT:
        _inputType._right = false;
        break;
      default:
        break;
    }
  }
}

/**
 * Handle the movement of the player.
 * @return void
 */
void Player::HandleMove() {
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

  Base::HandleMove();
}

/**
 * Handle the attack of the player.
 * @return void
 */
void Player::HandleAttack(SDL_Renderer *screen) {
  if (_state == ATTACKING) {
    return;
  }

  _state = ATTACKING;
  _currentFrame = 0;
  CreateBulletViaLevel(screen);

  SoundEffect::PlaySound(SOUND_EFFECT::ATTACK);
}

/**
 * Load the texture of the player based on the state of the player.
 * @param SDL_Renderer* screen
 * @return void
 */
void Player::LoadTextureViaState(SDL_Renderer *screen) {
  if (_state == ATTACKING) {
    LoadTexture("/player/attacking.png", screen);
  } else {
    LoadTexture("/player/flying.png", screen);
  }
}

/**
 * Create the bullet based on the level of the player.
 * @param SDL_Renderer* screen
 * @return void
 */
void Player::CreateBulletViaLevel(SDL_Renderer *screen) {
  if (_level <= 0) {
    _bullets.push_back(new Bullet(BULLET_TYPE::NORMAL, _xPos + _widthFrame, _yPos, 0, screen));
  } else if (_level <= 2) {
    _bullets.push_back(new Bullet(BULLET_TYPE::NORMAL, _xPos + _widthFrame, _yPos, -1, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::NORMAL, _xPos + _widthFrame, _yPos, 0, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::NORMAL, _xPos + _widthFrame, _yPos, 1, screen));
  } else if (_level <= 5) {
    _bullets.push_back(new Bullet(BULLET_TYPE::MID, _xPos + _widthFrame, _yPos, -1, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::NORMAL, _xPos + _widthFrame, _yPos, 0, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::MID, _xPos + _widthFrame, _yPos, 1, screen));
  } else if (_level <= 7) {
    _bullets.push_back(new Bullet(BULLET_TYPE::PRO, _xPos + _widthFrame, _yPos, -1, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::MID, _xPos + _widthFrame, _yPos, 0, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::PRO, _xPos + _widthFrame, _yPos, 1, screen));
  } else if (_level <= 10) {
    _bullets.push_back(new Bullet(BULLET_TYPE::PRO, _xPos + _widthFrame, _yPos, -1, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::PROIZE, _xPos + _widthFrame, _yPos, 0, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::PRO, _xPos + _widthFrame, _yPos, 1, screen));
  } else if (_level <= 13) {
    _bullets.push_back(new Bullet(BULLET_TYPE::PRO, _xPos + _widthFrame, _yPos, -3, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::NORMALIZE, _xPos + _widthFrame, _yPos, -1, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::PROIZE, _xPos + _widthFrame, _yPos, 0, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::NORMALIZE, _xPos + _widthFrame, _yPos, 1, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::PRO, _xPos + _widthFrame, _yPos, 3, screen));
  } else if (_level <= 15) {
    _bullets.push_back(new Bullet(BULLET_TYPE::PROIZE, _xPos + _widthFrame, _yPos, -3, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::MIDIZE, _xPos + _widthFrame, _yPos, -1, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::NORMALIZE, _xPos + _widthFrame, _yPos, 0, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::MIDIZE, _xPos + _widthFrame, _yPos, 1, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::PROIZE, _xPos + _widthFrame, _yPos, 3, screen));
  } else if (_level <= 17) {
    _bullets.push_back(new Bullet(BULLET_TYPE::NORMALIZE, _xPos + _widthFrame, _yPos, -5, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::PROIZE, _xPos + _widthFrame, _yPos, -3, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::MIDIZE, _xPos + _widthFrame, _yPos, -1, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::NORMALIZE, _xPos + _widthFrame, _yPos, 0, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::MIDIZE, _xPos + _widthFrame, _yPos, 1, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::PROIZE, _xPos + _widthFrame, _yPos, 3, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::NORMALIZE, _xPos + _widthFrame, _yPos, 5, screen));
  } else if (_level > 17) {
    _bullets.push_back(new Bullet(BULLET_TYPE::MIDIZE, _xPos + _widthFrame, _yPos, -9, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::PROIZE, _xPos + _widthFrame, _yPos, -7, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::NORMALIZE, _xPos + _widthFrame, _yPos, -5, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::PROIZE, _xPos + _widthFrame, _yPos, -3, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::NORMALIZE, _xPos + _widthFrame, _yPos, -1, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::PROIZE, _xPos + _widthFrame, _yPos, 0, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::NORMALIZE, _xPos + _widthFrame, _yPos, 1, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::PROIZE, _xPos + _widthFrame, _yPos, 3, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::NORMALIZE, _xPos + _widthFrame, _yPos, 5, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::PROIZE, _xPos + _widthFrame, _yPos, 7, screen));
    _bullets.push_back(new Bullet(BULLET_TYPE::MIDIZE, _xPos + _widthFrame, _yPos, 9, screen));
  }
}
