//
// Created by Study Together on 2024/02/16.
//

#include "Bullet.h"

/**
 * Constructor of Bullet class to initialize the properties of the bullet.
 * @return void
 */
Bullet::Bullet() {
  _widthFrame = 0;
  _heightFrame = 0;
}

/**
 * Destructor of Bullet class to free the memory of the bullet after the game is over.
 * @return void
 */
Bullet::~Bullet() {
  Free();
}

/**
 * Constructor of Bullet class to initialize the properties of the bullet and load the texture of the bullet.
 * @param bulletType
 * @param xPos
 * @param yPos
 * @param screen
 */
Bullet::Bullet(BULLET_TYPE bulletType, int xPos, int yPos, SDL_Renderer* screen) {
  loadBulletViaType(bulletType, screen);
  _xPos = xPos;
  _yPos = yPos + 20;
}

/**
 * Load the bullet via the type of the bullet.
 * @param SDL_Renderer* screen
 * @return void
 */
void Bullet::loadBulletViaType(BULLET_TYPE bulletType, SDL_Renderer * screen) {
  _bulletType = bulletType;

  switch (_bulletType) {
    case BULLET_TYPE::NORMAL:
      LoadTexture("/bullet/normal.png", screen);
      _rect = {0, 0, 27, 9};
      _speed = 10; _damage = 20; _deviation = 0;
      break;
    default:
      break;
  }
}

/**
 * Render the bullet on the screen.
 * @param SDL_Renderer* screen
 * @return void
 */
void Bullet::Render(SDL_Renderer* screen, SDL_Rect *clip, SDL_Rect *rect) {
  _xPos += _speed;
  _yPos += _deviation;

  if (rect == nullptr) {
    rect = new SDL_Rect({ _xPos, _yPos, _rect.w, _rect.h });
  }

  Base::Render(screen, clip, rect);
}

/**
 * Render the bullets on the screen.
 * @param SDL_Renderer* screen
 * @param std::vector<Base*> &bullets
 * @return void
 */
void Bullet::RenderBullets(SDL_Renderer* screen, std::vector<Base*> &bullets) {
  for (int i = 0; i < bullets.size(); i++) {
    Base* bullet = bullets.at(i);
    if (bullet != NULL) {
      bullet->Render(screen);
    }
  }

  ClearBullets(bullets);
}

/**
 * Clear the bullets from the screen.
 * @param std::vector<Base*> &bullets
 * @return void
 */
void Bullet::ClearBullets(std::vector<Base*> &bullets) {
  for (int i = 0; i < bullets.size(); i++) {
    Base* bullet = bullets.at(i);
    if (bullet != NULL) {
      if (bullet->GetRect().x > GAME_SCREEN_WIDTH) {
        bullets.erase(bullets.begin() + i);
        if (bullet != NULL) {
          delete bullet;
          bullet = NULL;
        }
      }
    }
  }
}
