
#include "canvas.hh"
#include "point.hh"

#include <iostream>
#include <string>
#include <vector>

#include <png.h>
#include <stdio.h>

#include "pngHelper.hh"

Canvas::Canvas(const Point &center, double width, double height, int horPixels,
               int vertPixels)
    : _center(center), _width(width), _height(height), _horPixels(horPixels),
      _vertPixels(vertPixels) {
  _pixels.resize(horPixels, std::vector<double>(vertPixels));
}

Point Canvas::coord(int i, int j) const {
  if (i < 0 || i >= _horPixels || j < 0 || j >= _vertPixels)
    return Point();

  Point bottomLeft(_center.x() - 0.5 * _width, _center.y() - 0.5 * _height);

  double x = bottomLeft.x() + i * (_width / (_horPixels - 1));
  double y = bottomLeft.y() + j * (_height / (_vertPixels - 1));

  return Point(x, y);
}

void Canvas::fill(std::function<double(int, int)> fillFunction) {
  for (int i = 0; i < _horPixels; i++) {
    for (int j = 0; j < _vertPixels; j++) {
      double d = fillFunction(i, j);
      _pixels[i][j] = d;
    }
  }

  _maxVal = 0;

  for (auto row: _pixels) {
    double tempMax = *std::max_element(row.begin(), row.end());

    if (tempMax > _maxVal)
      _maxVal = tempMax;
  }
}

void Canvas::print() {
  for (unsigned i = 0; i < _pixels.size(); i++) {
    for (unsigned j = 0; j < _pixels[i].size(); j++) {
      std::cout << pixel(i, j) << ", ";
    }
  }
}

int Canvas::pixel(int i, int j) {
  if (i < 0 || i > _horPixels || j < 0 || j > _vertPixels) {
    return -1;
  }

  return (int)(255 * (_pixels[i][j]) / (_maxVal));
}

bool Canvas::writePng(const std::string &fileName) {

  int **pixelPng;

  pixelPng = new int*[_horPixels];

  for (int i = 0; i < _horPixels; i++) {
    pixelPng[i] = new int[_vertPixels];
    for (int j = 0; j < _vertPixels; j++) {
      pixelPng[i][j] = pixel(i, j);
    }
  }


  return PngHelper::writePng(fileName, pixelPng, _horPixels, _vertPixels);
}