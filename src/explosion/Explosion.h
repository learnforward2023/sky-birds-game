//
// Created by Study Together on 2024/02/17.
//

#ifndef SKY_BIRDS_GAME_EXPLOSION_H
#define SKY_BIRDS_GAME_EXPLOSION_H

#include "../common/Common.h"
#include "../base/Base.h"

class Explosion : public Base {
  protected:

  public:
    Explosion(int xPos, int yPos, SDL_Renderer* screen);
    ~Explosion();

    void Render(SDL_Renderer* screen);
};

#endif //SKY_BIRDS_GAME_EXPLOSION_H
