//
// Created by Study Together on 2024/02/17.
//

#ifndef SKY_BIRDS_GAME_ALIEN_H
#define SKY_BIRDS_GAME_ALIEN_H

#include "../common/Common.h"
#include "../enemy/Enemy.h"

class Alien : public Enemy {
  private:

  public:
    Alien(SDL_Renderer *screen);
    ~Alien();

    void HandleAttackRandomly(SDL_Renderer* screen);
};

#endif //SKY_BIRDS_GAME_ALIEN_H
