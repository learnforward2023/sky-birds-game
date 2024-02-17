//
// Created by Study Together on 2024/02/17.
//

#ifndef SKY_BIRDS_GAME_HORN_H
#define SKY_BIRDS_GAME_HORN_H

#include "../common/Common.h"
#include "../enemy/Enemy.h"

class Horn : public Enemy {
  private:

  public:
    Horn(SDL_Renderer *screen);
    ~Horn();

    void HandleAttackRandomly(SDL_Renderer* screen);
};

#endif //SKY_BIRDS_GAME_HORN_H
