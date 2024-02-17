//
// Created by Study Together on 2024/02/17.
//

#ifndef SKY_BIRDS_GAME_ENEMY_H
#define SKY_BIRDS_GAME_ENEMY_H

#include "../common/Common.h"
#include "../base/Base.h"

class Enemy : public Base {
  protected:
    std::vector<Base*> _bullets;
    ENEMY_TYPE _type;
    int _hp;
    int _deviation;

  public:
    Enemy();
    ~Enemy();

    void LoadTextureViaState(SDL_Renderer *screen);
    void HandleMove();
    void Render(SDL_Renderer* screen);
    void HandleRandomMove(SDL_Renderer* screen);
    virtual void HandleAttackRandomly(SDL_Renderer* screen) {};

    void SetHP(int hp) { _hp = hp; }
    int GetHP() { return _hp; }
};

#endif //SKY_BIRDS_GAME_ENEMY_H
