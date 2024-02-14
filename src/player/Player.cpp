//
// Created by Study Together on 2024/02/11.
//

#include "Player.h"

/**
 * Constructor of Player class to initialize the properties of the player.
 * @return void
 */
Player::Player() {
  _widthFrame = 0;
  _heightFrame = 0;
  _currentFrame = 0;
}

/**
 * Constructor of Player class to initialize the properties of the player and load the texture of the player.
 * @param SDL_Renderer* screen
 * @return void
 */
Player::Player(SDL_Renderer* screen) {
  _widthFrame = 0;
  _heightFrame = 0;
  _currentFrame = 0;
  _speed = 10;

  LoadTexture("/player/flying.png", screen);
  SetFrameClip();

  char *basePath = SDL_GetBasePath();
  std::string soundPath = basePath ? basePath : "";
  soundPath += "../assets/sound_effects/attacking.wav";

  _attackSound = Mix_LoadWAV(soundPath.c_str());
  if (!_attackSound) {
    printf("Failed to load shooting sound: %s\n", Mix_GetError());
    // Handle the error accordingly
  }
}

/**
 * Destructor of Player class to free the memory of the player after the game is over.
 * @return void
 */
Player::~Player() {
  Free();
}

/**
 * Render the player on the screen.
 * @param SDL_Renderer* screen
 * @return void
 */
void Player::Render(SDL_Renderer* screen) {
  if (_currentFrame >= 10) {
    _currentFrame = 0;

    if (_state == CHARACTER_STATE::ATTACKING) {
      _state = CHARACTER_STATE::FLYING;
    }
  }

  if (_state == ATTACKING) {
    LoadTexture("/player/attacking.png", screen);
  } else {
    LoadTexture("/player/flying.png", screen);
  }

  HandleMove();

  SDL_Rect* currentClip = &_frameClip[_currentFrame];
  SDL_Rect renderQuad = { _xPos, _yPos, _widthFrame, _heightFrame };
  Base::Render(screen, currentClip, &renderQuad);

  _currentFrame++;
}

/**
 * Set the frame clip of the player,
 * @return void
 */
void Player::HandleInputAction(SDL_Event event, SDL_Renderer* screen) {
  if (event.type == SDL_KEYDOWN) {
    HandleKeyDown(event);
  } else if (event.type == SDL_KEYUP) {
    HandleKeyUp(event);
  }
}

/**
 * Handle the key down event of the player.
 * @param SDL_Event event
 * @return void
 */
void Player::HandleKeyDown(SDL_Event event) {
  if (event.type == SDL_KEYDOWN) {
    switch (event.key.keysym.sym) {
      case SDLK_UP:
        _inputType._up = true;
        break;
      case SDLK_DOWN:
        _inputType._down = true;
        break;
      case SDLK_LEFT:
        _inputType._left = true;
        break;
      case SDLK_RIGHT:
        _inputType._right = true;
        break;
      case SDLK_SPACE:
        _state = ATTACKING;
        // Play the shooting sound
        if (Mix_PlayChannel(-1, _attackSound, 0) == -1) {
          printf("Failed to play shooting sound: %s\n", Mix_GetError());
          // Handle the error accordingly
        }
        break;
      default:
        break;
    }
  }
}

/**
 * Handle the key up event of the player.
 * @param SDL_Event event
 * @return void
 */
void Player::HandleKeyUp(SDL_Event event) {
  if (event.type == SDL_KEYUP) {
    switch (event.key.keysym.sym) {
      case SDLK_UP:
        _inputType._up = false;
        break;
      case SDLK_DOWN:
        _inputType._down = false;
        break;
      case SDLK_LEFT:
        _inputType._left = false;
        break;
      case SDLK_RIGHT:
        _inputType._right = false;
        break;
      default:
        break;
    }
  }
}

/**
 * Handle the movement of the player.
 * @return void
 */
void Player::HandleMove() {
  if (_inputType._up && _yPos < 0) {
    _inputType._up = false;
  }

  if (_inputType._down && _yPos > GAME_SCREEN_HEIGHT - _heightFrame) {
    _inputType._down = false;
  }

  if (_inputType._left && _xPos < 0) {
    _inputType._left = false;
  }

  if (_inputType._right && _xPos > GAME_SCREEN_WIDTH - _widthFrame) {
    _inputType._right = false;
  }

  Base::HandleMove();
}
