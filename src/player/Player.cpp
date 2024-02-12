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
