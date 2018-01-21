#include "mandelbrot.hh"

#include <complex>
#include <iostream>

#include "rgbhsl.hh"

Mandelbrot::Mandelbrot(SDL_Renderer *ren, Point center, double width, double height, int horPixels, int vertPixels)
  :ren(ren)
  ,canvas(center, width, height, horPixels * 10, vertPixels * 10) { 
}

double Mandelbrot::mapVal(double val, double valMax, double valMin, double newMax, double newMin) {
  return ( val - valMin ) * ( newMax - newMin ) / ( valMax - valMin ) + newMin;
}

void Mandelbrot::calcPixels(double threshold, int maxIt) {

  this->threshold = threshold;
  this->iterations = maxIt;

  for (int i = 0; i < this->canvas.horPixels(); i++) {
    for (int j=0; j<this->canvas.vertPixels(); j++) {
      std::complex<double> c(
        this->canvas.coord(i, j).x(),
        this->canvas.coord(i, j).y()
      );
      std::complex<double> z = 0;
      int iterationCount;

      // std::cout << "debug\n";

      for(iterationCount = 0; iterationCount < maxIt && std::abs(z) < threshold; iterationCount++ ) {
        z = this->calcValue(z, c);
      }

      this->canvas(i, j) = (iterationCount >= maxIt) ? 0 : (int)Mandelbrot::mapVal(iterationCount, maxIt, 0, 255, 1);
    }
  }
}

void Mandelbrot::render() {
  for (int i = 0; i < this->canvas.horPixels() / 10; i+=10) {
    for (int j = 0; j < this->canvas.vertPixels() / 10; j+=10) {

      HsvColor colorHSV;
      colorHSV.h = (unsigned char)(this->canvas(i,j));

      colorHSV.s = 0xFF;
      colorHSV.v = 0xff;

      if (colorHSV.h == 0)
        colorHSV.v = 0;

      RgbColor rgbColor = HsvToRgb(colorHSV);

      SDL_SetRenderDrawColor(this->ren, rgbColor.r, rgbColor.g, rgbColor.b, 0x0);
      SDL_RenderDrawPoint(this->ren, i, j);
    }
  }

  SDL_RenderPresent(this->ren);
}

void Mandelbrot::zoom(Point newCenter) {

  
}