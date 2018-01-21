#include <SDL2/SDL.h>
#include <iostream>

#include "mandelbrot.hh"
#include "point.hh"

const int width = 1280;
const int height = 720;

int main() {
  SDL_Window *win;
  SDL_Renderer *ren;

  SDL_Init(SDL_INIT_VIDEO);
  win = SDL_CreateWindow("Mandelbrot", 0, 0, width, height, SDL_WINDOW_SHOWN);
  ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  Mandelbrot mb(ren, Point(-1, 0), 16, 9, width, height);
  mb.calcPixels(10, 4000);

  bool quit = false;
  SDL_Event event;

  int x,y;

  mb.render();

  while (!quit) {
    SDL_WaitEvent(&event);
    switch (event.type) {
      case SDL_QUIT:
        quit = true;
        break;
      case SDL_MOUSEBUTTONDOWN:
        SDL_GetMouseState(&x,&y);
        std::cout << "x = " << x << ", y = " << y << std::endl;
        mb.zoom(Point(x,y));
        break;
    }
  }

  SDL_DestroyRenderer(ren);
  SDL_DestroyWindow(win);
  SDL_Quit();

  return 0;
}
