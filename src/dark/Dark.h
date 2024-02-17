//
// Created by Study Together on 2024/02/17.
//

#ifndef SKY_BIRDS_GAME_DARK_H
#define SKY_BIRDS_GAME_DARK_H

#include "../common/Common.h"
#include "../enemy/Enemy.h"

class Dark : public Enemy {
  private:

  public:
    Dark(SDL_Renderer *screen);
    ~Dark();

    void HandleAttackRandomly(SDL_Renderer* screen);
};

#endif //SKY_BIRDS_GAME_DARK_H
