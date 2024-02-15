//
// Created by Study Together on 2024/02/11.
// https://studytogether.vn
//

#ifndef SKY_BIRDS_GAME_COMMON_H
#define SKY_BIRDS_GAME_COMMON_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>

extern const int GAME_SCREEN_WIDTH;
extern const int GAME_SCREEN_HEIGHT;
extern const char* GAME_TITLE;
extern const int NUMBER_OF_FRAMES;

struct Input {
  bool _left, _right, _up, _down;
};

#endif //SKY_BIRDS_GAME_COMMON_H
