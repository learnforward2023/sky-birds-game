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

    void loadBulletViaType(BULLET_TYPE bulletType, SDL_Renderer *screen);

  public:
    Bullet();
    Bullet(BULLET_TYPE bulletType, int xPos, int yPos, SDL_Renderer *screen);
    ~Bullet();

    void Render(SDL_Renderer *screen, SDL_Rect *clip = nullptr, SDL_Rect *rect = nullptr);

    static void RenderBullets(SDL_Renderer *screen, std::vector<Base*> &bullets);
    static void ClearBullets(std::vector<Base*> &bullets);
};

#endif //SKY_BIRDS_GAME_BULLET_H
