//
// Created by Study Together on 2024/02/17.
//

#ifndef SKY_BIRDS_GAME_ENEMY_H
#define SKY_BIRDS_GAME_ENEMY_H

#include "../common/Common.h"
#include "../base/Base.h"

class Enemy : public Base {
  private:
    std::vector<Base*> _bullets;
    ENEMY_TYPE _type;
    int _hp;

  public:
    Enemy();
    ~Enemy();
};

#endif //SKY_BIRDS_GAME_ENEMY_H
