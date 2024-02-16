//
// Created by Study Together on 2024/02/16.
//

#ifndef SKY_BIRDS_GAME_BULLET_H
#define SKY_BIRDS_GAME_BULLET_H

#include "../common/Common.h"
#include "../Base/Base.h"

class Bullet : public Base {
  private:
    BULLET_TYPE _bulletType;
    int _damage;
    int _deviation;

  public:
    Bullet();
    ~Bullet();
};

#endif //SKY_BIRDS_GAME_BULLET_H
