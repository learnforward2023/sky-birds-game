#include "src/common/Common.h"

#include "src/common/Common.cpp"
#include "src/Base/Base.cpp"
#include "src/player/Player.cpp"

static SDL_Window *window = nullptr;
static SDL_Renderer *screen = nullptr;
static SDL_Event event;

/**
 * Function declarations
 */
Base* loadBackground();
bool initialize();
void cleanup();

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
