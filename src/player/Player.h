//
// Created by Study Together on 2024/02/11.
//

#ifndef SKY_BIRDS_GAME_PLAYER_H
#define SKY_BIRDS_GAME_PLAYER_H

#include "../common/Common.h"
#include "../Base/Base.h"
#include "../bullet/Bullet.h"

class Player : public Base {
  private:
    std::vector<Base*> _bullets;
    int _level;

    void HandleKeyUp(SDL_Event event);
    void HandleKeyDown(SDL_Event event, SDL_Renderer *screen);
    void HandleMove();
    void HandleAttack(SDL_Renderer *screen);
    void LoadTextureViaState(SDL_Renderer *screen);
    void CreateBulletViaLevel(SDL_Renderer *screen);

  public:
    Player();
    Player(SDL_Renderer *screen);
    ~Player();

    std::vector<Base*> GetBullets() { return _bullets; }

    void Render(SDL_Renderer* screen);
    void HandleInputAction(SDL_Event event, SDL_Renderer *screen);
};

#endif //SKY_BIRDS_GAME_PLAYER_H
