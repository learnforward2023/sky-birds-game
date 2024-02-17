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
    CHARACTER_STATE _state;

  public:
    Base();
    ~Base();

    void SetRect(const SDL_Rect &rect) { _rect = rect; }
    SDL_Rect GetRect() const { return _rect; }
    void SetState(const CHARACTER_STATE &state) { _state = state; }
    CHARACTER_STATE GetState() const { return _state; }
    int GetXPos() const { return _xPos; }
    int GetYPos() const { return _yPos; }

    void Free();
    bool LoadTexture(const std::string &path, SDL_Renderer* screen);
    virtual void Render(SDL_Renderer* des, SDL_Rect *clip = nullptr, SDL_Rect *rect = nullptr);
    void SetFrameClip();
    SDL_Surface* LoadSurface(const std::string &path);
    void HandleMove();
};

#endif //SKY_BIRDS_GAME_BASE_H
