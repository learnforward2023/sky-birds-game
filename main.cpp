#include <SDL.h>

static SDL_Window *window = nullptr;
static SDL_Renderer *screen = nullptr;
static SDL_Event event;
const int GAME_SCREEN_WIDTH = 1400;
const int GAME_SCREEN_HEIGHT = 740;
const char* GAME_TITLE = "Study Together - Sky Birds Game";

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
    SDL_SetRenderDrawColor(screen, 0, 0, 0, 255);
    SDL_RenderClear(screen);

    // Draw your game elements here

    // Update the screen
    SDL_RenderPresent(screen);
  }

  // Cleanup
  SDL_DestroyRenderer(screen);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
