//
// Created by Study Together on 2024/02/17.
//

#include "Explosion.h"

/**
* Explosion constructor
* @return
*/
Explosion::Explosion(int xPos, int yPos, SDL_Renderer* screen) {
  LoadTexture("/effect/explosion.png", screen);
  SetFrameClip();
  _xPos = xPos;
  _yPos = yPos;
}

/**
 * Explosion destructor
 * @return
 */
Explosion::~Explosion() {
  Free();
}

/**
 * Render enemy
 * @param screen
 */
void Explosion::Render(SDL_Renderer *screen) {
  if (_currentFrame >= 10) {
    _currentFrame = 0;
    _state = CHARACTER_STATE::DEAD;
  }

  SDL_Rect* currentClip = &_frameClip[_currentFrame];
  SDL_Rect renderQuad = { _xPos, _yPos, _widthFrame, _heightFrame };
  Base::Render(screen, currentClip, &renderQuad);

  _currentFrame++;
}
