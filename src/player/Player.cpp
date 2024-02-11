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

  _frameClip[0].x = 0;
  _frameClip[0].y = 0;
  _frameClip[0].w = _widthFrame;
  _frameClip[0].h = _heightFrame;

  _frameClip[1].x = _widthFrame;
  _frameClip[1].y = 0;
  _frameClip[1].w = _widthFrame;
  _frameClip[1].h = _heightFrame;

  _frameClip[2].x = 2 * _widthFrame;
  _frameClip[2].y = 0;
  _frameClip[2].w = _widthFrame;
  _frameClip[2].h = _heightFrame;

  _frameClip[3].x = 3 * _widthFrame;
  _frameClip[3].y = 0;
  _frameClip[3].w = _widthFrame;
  _frameClip[3].h = _heightFrame;

  _frameClip[4].x = 4 * _widthFrame;
  _frameClip[4].y = 0;
  _frameClip[4].w = _widthFrame;
  _frameClip[4].h = _heightFrame;

  _frameClip[5].x = 5 * _widthFrame;
  _frameClip[5].y = 0;
  _frameClip[5].w = _widthFrame;
  _frameClip[5].h = _heightFrame;

  _frameClip[6].x = 6 * _widthFrame;
  _frameClip[6].y = 0;
  _frameClip[6].w = _widthFrame;
  _frameClip[6].h = _heightFrame;

  _frameClip[7].x = 7 * _widthFrame;
  _frameClip[7].y = 0;
  _frameClip[7].w = _widthFrame;
  _frameClip[7].h = _heightFrame;

  _frameClip[8].x = 8 * _widthFrame;
  _frameClip[8].y = 0;
  _frameClip[8].w = _widthFrame;
  _frameClip[8].h = _heightFrame;

  _frameClip[9].x = 9 * _widthFrame;
  _frameClip[9].y = 0;
  _frameClip[9].w = _widthFrame;
  _frameClip[9].h = _heightFrame;
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
