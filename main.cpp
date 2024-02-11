#include "src/common/Common.h"

#include "src/common/Common.cpp"
#include "src/Base/Base.cpp"

static SDL_Window *window = nullptr;
static SDL_Renderer *screen = nullptr;
static SDL_Event event;

Base* loadBackground() {
  Base* background = new Base();
  background->LoadTexture("/background/primary.png", screen);
  SDL_Rect rect = {0, 0, GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGHT};
  background->SetRect(rect);

  return background;
}

int main(int argc, char* args[]) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return 1;
  }

  // Create a window
  window = SDL_CreateWindow(GAME_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (window == nullptr) {
    printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    return 1;
  }

  // Create a screen to render the game
  screen = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (screen == nullptr) {
    printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
    return 1;
  }

  // Load the background
  Base* background = loadBackground();

  // Main game loop
  bool quit = false;
  while (!quit) {
    // Event handling
    while (SDL_PollEvent(&event) != 0) {
      if (event.type == SDL_QUIT) {
        quit = true;
      }
    }

    // Clear the screen
    SDL_RenderClear(screen);

    // Draw your game elements here
    background->Render(screen);

    // Update the screen
    SDL_RenderPresent(screen);
  }

  // Cleanup
  SDL_DestroyRenderer(screen);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
