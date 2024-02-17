//
// Created by Study Together on 2024/02/11.
// https://studytogether.vn
//

#ifndef SKY_BIRDS_GAME_COMMON_H
#define SKY_BIRDS_GAME_COMMON_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <string>

extern const int GAME_SCREEN_WIDTH;
extern const int GAME_SCREEN_HEIGHT;
extern const char* GAME_TITLE;
extern const int NUMBER_OF_FRAMES;
extern const int GAME_FPS;
extern const int GAME_TICKS_PER_FRAME;

struct Input {
  bool _left, _right, _up, _down;
};

enum CHARACTER_STATE {
  FLYING = 0,
  ATTACKING,
};

enum SOUND_EFFECT {
  ATTACK = 0,
};

enum BULLET_TYPE {
  NORMAL = 0,
  MID,
  PRO,
  NORMALIZE,
  MIDIZE,
  PROIZE,
  E_NORMAL,
  E_MID,
  E_PRO,
  E_NORMALIZE,
  E_MIDIZE,
  E_PROIZE,
};

enum ENEMY_TYPE {
  ALIEN = 0,
  DARK,
  EYE,
  HORN,
};

#endif //SKY_BIRDS_GAME_COMMON_H
