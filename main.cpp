#include "src/common/Common.h"

static SDL_Window *window = nullptr;
static SDL_Renderer *screen = nullptr;
static SDL_Event event;

void renderBackground() {
  // Get the base path for the game application
  std::string basePath = SDL_GetBasePath();
  // Append the image to the base path
  std::string backgroundPath = basePath.append("../assets/images/background/primary.png");

  // Load Background image
  SDL_Surface* backgroundSurface = IMG_Load(backgroundPath.c_str());
  if (backgroundSurface == nullptr) {
    printf("Unable to load image %s! SDL Error: %s\n", backgroundPath.c_str(), SDL_GetError());

    return;
  }

  // Create texture from surface pixels
  SDL_Texture* backgroundTexture = SDL_CreateTextureFromSurface(screen, backgroundSurface);
  if (backgroundTexture == nullptr) {
    printf("Unable to create texture from %s! SDL Error: %s\n", backgroundPath.c_str(), SDL_GetError());

    return;
  }

  SDL_FreeSurface(backgroundSurface); // Free the surface after creating the texture
  SDL_Rect backgroundRect = {0, 0, GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGHT};

  // Render the background
  SDL_RenderCopy(screen, backgroundTexture, nullptr, &backgroundRect);
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
    renderBackground();

    // Update the screen
    SDL_RenderPresent(screen);
  }

  // Cleanup
  SDL_DestroyRenderer(screen);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
