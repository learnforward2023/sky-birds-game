//
// Created by Study Together on 2024/02/11.
//

#include "Base.h"

/**
 * Constructor for the Base class, initialize the values
 * @return void
 */
Base::Base() {
  _xPos = 0;
  _yPos = 0;
  _texture = nullptr;
}

/**
 * Destructor for the Base class, free the texture
 * @return void
 */
Base::~Base() {
  Free();
}

/**
 * Free the texture and set it to nullptr
 * @return void
 */
void Base::Free() {
  if (_texture != nullptr) {
    SDL_DestroyTexture(_texture);
    _texture = nullptr;
  }
}

/**
 * Load the surface from the file path
 * @param path The path to the image
 * @return The surface loaded from the image if successful, nullptr otherwise
 */
SDL_Surface* Base::LoadSurface(const std::string &path) {
  std::string basePath = SDL_GetBasePath();
  std::string imagesPath = basePath.append("../assets/images");
  std::string fullPath = imagesPath.append(path);

  SDL_Surface* loadedSurface = IMG_Load(fullPath.c_str());
  if (loadedSurface == nullptr) {
    printf("Unable to load image %s! SDL_image Error: %s\n", fullPath.c_str(), IMG_GetError());

    return nullptr;
  }

  return loadedSurface;
}

/**
 * Load the texture from the file path
 * @param path The path to the image
 * @param screen The renderer
 * @return true if the texture was loaded successfully, false otherwise
 */
bool Base::LoadTexture(const std::string &path, SDL_Renderer* screen) {
  Free();

  SDL_Texture* newTexture = nullptr;
  SDL_Surface* loadedSurface = LoadSurface(path);

  if (loadedSurface != nullptr) {
    SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
    newTexture = SDL_CreateTextureFromSurface(screen, loadedSurface);

    if (newTexture == nullptr) {
      printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());

      return false;
    }

    _rect.w = loadedSurface->w;
    _rect.h = loadedSurface->h;
    _widthFrame = _rect.w / NUMBER_OF_FRAMES;
    _heightFrame = _rect.h;

    SDL_FreeSurface(loadedSurface);
  }

  _texture = newTexture;

  return _texture != nullptr;
}

/**
 * Render the texture to the screen
 * @param des The renderer
 * @param clip The clip to render
 * @param rect The destination rectangle, if null the default rectangle will be used
 * @return void
 */
void Base::Render(SDL_Renderer* des, SDL_Rect *clip, SDL_Rect *rect) {
  if (_texture == nullptr) {
    return;
  }

  SDL_Rect renderQuad = { _xPos, _yPos, _rect.w, _rect.h };

  if (rect != nullptr) {
    renderQuad.w = rect->w;
    renderQuad.h = rect->h;
    renderQuad.x = rect->x;
    renderQuad.y = rect->y;
  }

  SDL_RenderCopy(des, _texture, clip, &renderQuad);
}

/**
 * Set the frame clip of the player.
 * @return void
 */
void Base::SetFrameClip() {
  if (_widthFrame <= 0 & _heightFrame <= 0) {
    return;
  }

  for (int i = 0; i < NUMBER_OF_FRAMES; i++) {
    _frameClip[i].x = i * _widthFrame;
    _frameClip[i].y = 0;
    _frameClip[i].w = _widthFrame;
    _frameClip[i].h = _heightFrame;
  }
}

/**
 * Handle the movement of the player.
 * @return void
 */

void Base::HandleMove() {
  if (_inputType._up) {
    _yPos -= _speed;
  }

  if (_inputType._down) {
    _yPos += _speed;
  }

  if (_inputType._left) {
    _xPos -= _speed;
  }

  if (_inputType._right) {
    _xPos += _speed;
  }
}
