//
// Created by Study Together on 2024/02/17.
//

#include "../common/Common.h"
#include "Dark.h"

/**
* Constructor of Dark class
* @return
*/
Dark::Dark(SDL_Renderer *screen) {
  _type = ENEMY_TYPE::DARK;
  _state = CHARACTER_STATE::FLYING;
  _hp = 100;
  _deviation = 0;

  LoadTextureViaState(screen);
}

/**
* Destructor of Dark class
 * @return
*/

Dark::~Dark() {
  Free();
}
