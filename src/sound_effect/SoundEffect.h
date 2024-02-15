//
// Created by Study Together on 2024/02/15.
//

#ifndef SKY_BIRDS_GAME_SOUNDEFFECT_H
#define SKY_BIRDS_GAME_SOUNDEFFECT_H

#include "../common/Common.h"

class SoundEffect {
  private:
    static Mix_Chunk* _attackSound;
    static Mix_Chunk* LoadSound(const std::string &path);

  public:
    SoundEffect();
    ~SoundEffect();

    static void PlaySound(const SOUND_EFFECT &soundEffect);
};

#endif //SKY_BIRDS_GAME_SOUNDEFFECT_H
