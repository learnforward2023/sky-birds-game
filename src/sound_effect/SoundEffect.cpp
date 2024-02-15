//
// Created by Study Together on 2024/02/15.
//

#include "SoundEffect.h"

Mix_Chunk* SoundEffect::_attackSound = NULL;

/**
 * Constructor of SoundEffect class to initialize the properties of the sound effect.
 * @return void
 */
SoundEffect::SoundEffect() {
  if (_attackSound == NULL) {
    _attackSound = LoadSound("/attacking.wav");
  }
}

/**
 * Destructor of SoundEffect class to free the memory of the sound effect after the game is over.
 * @return void
 */
SoundEffect::~SoundEffect() {
  if (_attackSound != NULL) {
    Mix_FreeChunk(_attackSound);
    _attackSound = NULL;
  }
}

/**
 * Load the sound effect from the file path
 * @param path The path to the sound effect
 * @return The sound effect loaded if successful, nullptr otherwise
 */
Mix_Chunk* SoundEffect::LoadSound(const std::string &path) {
  std::string basePath = SDL_GetBasePath();
  std::string soundPath = basePath.append("../assets/sound_effects");
  soundPath += path;

  Mix_Chunk* sound = Mix_LoadWAV(soundPath.c_str());
  if (sound == NULL) {
    printf("Failed to load sound effect: %s\n", Mix_GetError());

    return nullptr;
  }

  return sound;
}

/**
 * Play the sound effect.
 * @param soundEffect The sound effect to play
 * @return void
 */
void SoundEffect::PlaySound(const SOUND_EFFECT &soundEffect) {
  switch (soundEffect) {
    case SOUND_EFFECT::ATTACK:
      Mix_PlayChannel(-1, _attackSound, 0);
      break;
  }
}
