
#include "canvas.hh"
#include "point.hh"

#include <iostream>
#include <string>
#include <vector>

#include <png.h>
#include <stdio.h>

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
  for (unsigned i = 0; i < _pixels.size(); i++) {
    for (unsigned j = 0; j < _pixels[i].size(); j++) {
      double d = fillFunction(i, j);
      _pixels[i][j] = d;
    }
  }

  _maxVal = 0;
  for (auto horVec : _pixels) {
    double tempMax = *(std::max_element(horVec.begin(), horVec.end()));
    if (tempMax >= _maxVal)
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
  if (i < 0 || i > _horPixels || j < 0 || j > _vertPixels)
    return 0;

  return (int)(_pixels[i][j] * 65535 / _maxVal);
}

bool Canvas::writePng(std::string fileName) {
  std::ofstream file;
  file.open(fileName, std::ios::binary);

  if (file.is_open()) {

    file.close();
  } else {
    return false;
  }
}