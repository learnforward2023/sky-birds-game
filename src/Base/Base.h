//
// Created by Study Together on 2024/02/11.
//

#ifndef SKY_BIRDS_GAME_BASE_H
#define SKY_BIRDS_GAME_BASE_H

#include "../common/Common.h"

class Base {
  private:
    int _xPos, _yPos;
    SDL_Rect _rect;
    SDL_Texture* _texture;

  protected:
    SDL_Surface* LoadSurface(const std::string &path);

  public:
    Base();
    ~Base();

    void SetRect(const SDL_Rect &rect) { _rect = rect; }

    void Free();
    bool LoadTexture(const std::string &path, SDL_Renderer* screen);
    void Render(SDL_Renderer* des, SDL_Rect *clip = nullptr, SDL_Rect *rect = nullptr);
};

#endif //SKY_BIRDS_GAME_BASE_H