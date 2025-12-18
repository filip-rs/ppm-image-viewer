#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdbool.h>
#include <stdlib.h>

#include <stdio.h>

#define SDL_HINT_QUIT_ON_LAST_WINDOW_CLOSE "SDL_QUIT_ON_LAST_WINDOW_CLOSE"

bool valid_length(int length_req, char *string);
void strip_string(char *s);

int main() {
  FILE *in = stdin;

  char *pthrowaway = calloc(1000, sizeof(char));

  // Read first line - specifier
  fgets(pthrowaway, 1000, in);
  free(pthrowaway);

  // Read SECOND line
  char *pdimensions = calloc(1000, sizeof(char));
  fgets(pdimensions, 1000, in);

  printf("%s", pdimensions);

  // Read the max value (and throw it out)
  pthrowaway = calloc(1000, sizeof(char));
  fgets(pthrowaway, 1000, in);
  free(pthrowaway);

  int width = -1;
  int height = -1;

  sscanf(pdimensions, "%d %d\n", &width, &height);

  printf("[DEBUG]: width: %d, height: %d\n", width, height);

  const char *title = "PPM image viewer";
  SDL_Window *pwindow = SDL_CreateWindow(
      title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

  SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);

  int x = 0;
  int y = 0;
  SDL_Rect pixel = (SDL_Rect){x, y, 1, 1};
  Uint32 color = 0;
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      Uint8 r, g, b;
      r = (char)getchar();
      g = (char)getchar();
      b = (char)getchar();
      Uint32 color = SDL_MapRGB(psurface->format, r, g, b);

      SDL_Rect pixel = {x, y, 1, 1};
      SDL_FillRect(psurface, &pixel, color);
    }
  }
  SDL_UpdateWindowSurface(pwindow);

  int app_running = 1;

  while (app_running) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        app_running = 0;
      }
    }
    SDL_Delay(100);
  }
}

void strip_string(char *s) {
  size_t len = strlen(s);
  if (len <= 2) {
    s[0] = '\0';
    return;
  }
  memmove(s, s + 2, len - 1); // includes '\0'
}
