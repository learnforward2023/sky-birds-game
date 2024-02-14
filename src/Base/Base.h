//
// Created by Study Together on 2024/02/11.
//

#ifndef SKY_BIRDS_GAME_BASE_H
#define SKY_BIRDS_GAME_BASE_H

#include "../common/Common.h"

class Base {
  protected:
    int _speed;
    Input _inputType;
    int _xPos, _yPos;
    SDL_Rect _rect;
    SDL_Texture* _texture;
    int _widthFrame, _heightFrame;
    int _currentFrame;
    SDL_Rect _frameClip[NUMBER_OF_FRAMES];

    SDL_Surface* LoadSurface(const std::string &path);

  public:
    Base();
    ~Base();

    void SetRect(const SDL_Rect &rect) { _rect = rect; }

    void Free();
    bool LoadTexture(const std::string &path, SDL_Renderer* screen);
    void Render(SDL_Renderer* des, SDL_Rect *clip = nullptr, SDL_Rect *rect = nullptr);
    void SetFrameClip();
};

#endif //SKY_BIRDS_GAME_BASE_H
