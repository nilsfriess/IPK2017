#ifndef MANDELBROT_HH
#define MANDELBROT_HH

#include <SDL2/SDL.h>
#include <complex>
#include <cmath>

#include "canvas.hh"

class Mandelbrot {
private:
  SDL_Renderer *ren;
  Canvas canvas;

  std::complex<double> calcValue(std::complex<double> z, std::complex<double> c) { return z*z + c; }

  double threshold;
  int iterations;

public:
  Mandelbrot(SDL_Renderer *ren, Point center, double width, double height, int horPixels, int vertPixels);
  // ~Mandelbrot() { delete canvas; }

  void calcPixels(double threshold, int maxIt);
  void render();

  void zoom(Point newCenter);

  static double mapVal(double val, double valMax, double valMin, double newMax, double newMin);

};

#endif // MANDELBROT_HH