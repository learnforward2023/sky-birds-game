//
// Created by Study Together on 2024/02/11.
//

#ifndef SKY_BIRDS_GAME_PLAYER_H
#define SKY_BIRDS_GAME_PLAYER_H

#include "../common/Common.h"
#include "../Base/Base.h"

class Player : public Base {
  private:
    void HandleKeyUp(SDL_Event event);
    void HandleKeyDown(SDL_Event event);

  public:
    Player();
    Player(SDL_Renderer *screen);
    ~Player();

    void Render(SDL_Renderer* screen);
    void HandleInputAction(SDL_Event event, SDL_Renderer *screen);
};

#endif //SKY_BIRDS_GAME_PLAYER_H
