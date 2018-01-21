#ifndef CANVAS_HH
#define CANVAS_HH

#include "point.hh"
#include <vector>
#include <functional>
#include <string>

class Canvas {
public:
  Canvas(const Point &, double, double, int, int);

  Point coord(int, int) const;

  int pixel(int i, int j);
  void fill(std::function<double(int, int)>);

  void print();

  bool writePng(const std::string &fileName);

private:
  const Point _center;
  const double _width;
  const double _height;
  const int _horPixels;
  const int _vertPixels;
  double _maxVal;
  std::vector<std::vector<double>> _pixels;
};

#endif // CANVAS_HH