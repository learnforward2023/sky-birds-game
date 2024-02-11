//
// Created by Study Together on 2024/02/11.
//

#include "Player.h"

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
 * Load the texture of the player. If the texture is loaded successfully, set the width and height of the frame.
 * @param const std::string &path
 * @param SDL_Renderer* screen
 * @return bool, true if the texture is loaded successfully, false otherwise
 */
void Player::LoadTexture(const std::string &path, SDL_Renderer* screen) {
  bool ret = Base::LoadTexture(path, screen);

  if (ret) {
    _widthFrame = _rect.w / 10;
    _heightFrame = _rect.h;
  }
}

/**
 * Set the frame clip of the player.
 * @return void
 */
void Player::SetFrameClip() {
  if (_widthFrame <= 0 & _heightFrame <= 0) {
    return;
  }

  for (int i = 0; i < 10; i++) {
    _frameClip[i].x = i * _widthFrame;
    _frameClip[i].y = 0;
    _frameClip[i].w = _widthFrame;
    _frameClip[i].h = _heightFrame;
  }
}

/**
 * Render the player on the screen.
 * @param SDL_Renderer* screen
 * @return void
 */
void Player::Render(SDL_Renderer* screen) {
  if (_currentFrame >= 10) {
    _currentFrame = 0;
  }

  SDL_Rect* currentClip = &_frameClip[_currentFrame];
  SDL_Rect renderQuad = { _xPos, _yPos, _widthFrame, _heightFrame };
  Base::Render(screen, currentClip, &renderQuad);

  _currentFrame++;
}
