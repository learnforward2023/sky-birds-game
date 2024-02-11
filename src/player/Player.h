//
// Created by Study Together on 2024/02/11.
//

#ifndef SKY_BIRDS_GAME_PLAYER_H
#define SKY_BIRDS_GAME_PLAYER_H

#include "../common/Common.h"
#include "../Base/Base.h"

class Player : public Base {
  private:
    int _widthFrame, _heightFrame;
    int _currentFrame;
    SDL_Rect _frameClip[10];

  public:
    Player();
    ~Player();

    void Render(SDL_Renderer* screen);
    void LoadTexture(const std::string &path, SDL_Renderer* screen);
    void SetFrameClip();
};

#endif //SKY_BIRDS_GAME_PLAYER_H
