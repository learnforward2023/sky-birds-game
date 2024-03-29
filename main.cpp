#include "src/common/Common.h"

#include "src/common/Common.cpp"
#include "src/Base/Base.cpp"
#include "src/player/Player.cpp"
#include "src/sound_effect/SoundEffect.cpp"
#include "src/bullet/Bullet.cpp"
#include "src/enemy/Enemy.cpp"
#include "src/dark/Dark.cpp"
#include "src/horn/Horn.cpp"
#include "src/alien/Alien.cpp"
#include "src/explosion/Explosion.cpp"

static SDL_Window *window = nullptr;
static SDL_Renderer *screen = nullptr;
static SDL_Event event;

/**
 * Function declarations
 */
Base* loadBackground();
bool initialize();
void cleanup();
void CreateAndRenderEnemies(std::vector<Enemy*> &enemies, SDL_Renderer* screen);
void CheckCollisionAndRenderExplosion(Player* player, std::vector<Enemy*> &enemies, std::vector<Explosion*> &explosions);

/**
 * Main function, the entry point of the game - Sky Birds Game with SDL 2 and C++ - Study Together
 * @param argc The number of arguments
 * @param args The arguments
 * @return The exit code
 */
int main(int argc, char* args[]) {
  if (!initialize()) {
    printf("Failed to initialize!\n");

    return -1;
  }

  Base* background = loadBackground();
  Player* player = new Player(screen);
  std::vector<Enemy*> enemies;
  std::vector<Explosion*> explosions;

  // Main game loop
  bool quit = false;
  while (!quit) {
    Uint32 frameStart = SDL_GetTicks();

    // Event handling
    while (SDL_PollEvent(&event) != 0) {
      if (event.type == SDL_QUIT) {
        quit = true;
      }

      player->HandleInputAction(event, screen);
    }

    // Clear the screen
    SDL_RenderClear(screen);

    // Draw your game elements here
    background->Render(screen);
    player->Render(screen);
    CreateAndRenderEnemies(enemies, screen);
    CheckCollisionAndRenderExplosion(player, enemies, explosions);

    // Update the screen
    SDL_RenderPresent(screen);

    int frameTime = SDL_GetTicks() - frameStart;
    if (frameTime < GAME_TICKS_PER_FRAME) {
      SDL_Delay(GAME_TICKS_PER_FRAME - frameTime);
    }
  }

  cleanup();

  return 0;
}

/**
 * Load the background
 * @return The background
 */
Base* loadBackground() {
  Base* background = new Base();
  background->LoadTexture("/background/primary.png", screen);
  SDL_Rect rect = {0, 0, GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGHT};
  background->SetRect(rect);

  return background;
}

/**
 * Initialize the game
 * @return true if the game was initialized successfully, false otherwise
 */
bool initialize() {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return false;
  }

  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
    printf("Failed to open audio: %s\n", Mix_GetError());
    return false;
  }

  // Create a window
  window = SDL_CreateWindow(GAME_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, GAME_SCREEN_WIDTH,
                            GAME_SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (window == nullptr) {
    printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());

    return false;
  }

  // Create a screen to render the game
  screen = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (screen == nullptr) {
    printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());

    return false;
  }

  // Init sound effect
  new SoundEffect();

  return true;
}

/**
 * Cleanup the game
 */
void cleanup() {
  SDL_DestroyRenderer(screen);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

/**
 * Create and render enemies
 * @param enemies The enemies
 * @param screen The screen
 */
void CreateAndRenderEnemies(std::vector<Enemy*> &enemies, SDL_Renderer* screen) {
  int currentTime = SDL_GetTicks();

  if (currentTime % 2000 < 20 && enemies.size() <= 10) {
    int randomType = rand() % 4;

    switch (randomType) {
      case 0:
        enemies.push_back(new Dark(screen));
        break;
      case 1:
        enemies.push_back(new Horn(screen));
        break;
      case 2:
        enemies.push_back(new Alien(screen));
        break;
      default:
        enemies.push_back(new Alien(screen));
        break;
    }
  }

  for (auto &enemy : enemies) {
    enemy->HandleRandomMove(screen);
  }

  // Remove the enemies from the screen if state is dead
  for (int i = 0; i < enemies.size(); i++) {
    Enemy* enemy = enemies.at(i);
    if (enemy->GetHP() <= 0) {
      enemies.erase(enemies.begin() + i);
      if (enemy != NULL) {
        delete enemy;
        enemy = NULL;
      }
    }
  }
}

/**
 * Check collision and render explosion
 * @param player The player
 * @param enemies The enemies
 * @param explosions The explosions
 */
void CheckCollisionAndRenderExplosion(Player* player, std::vector<Enemy*> &enemies, std::vector<Explosion*> &explosions) {
  for (auto &enemy : enemies) {
    for (auto &bullet : player->GetBullets()) {

      if (bullet->GetXPos() >= enemy->GetXPos() && bullet->GetXPos() <= enemy->GetXPos() + enemy->GetRect().w &&
          bullet->GetYPos() >= enemy->GetYPos() && bullet->GetYPos() <= enemy->GetYPos() + enemy->GetRect().h) {
        explosions.push_back(new Explosion(enemy->GetXPos(), bullet->GetYPos(), screen));
        bullet->SetState(CHARACTER_STATE::DEAD);
        enemy->SetHP(enemy->GetHP() - 20);
      }
    }
  }

  for (auto &explosion : explosions) {
    explosion->Render(screen);
  }

  // Clear the explosions from the screen if state is dead
  for (int i = 0; i < explosions.size(); i++) {
    Explosion* explosion = explosions.at(i);
    if (explosion->GetState() == CHARACTER_STATE::DEAD) {
      explosions.erase(explosions.begin() + i);
      if (explosion != NULL) {
        delete explosion;
        explosion = NULL;
      }
    }
  }
}
