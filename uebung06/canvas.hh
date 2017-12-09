#ifndef CANVAS_HH
#define CANVAS_HH

#include "point.hh"
#include <vector>

class Canvas {
public:
  Canvas(const Point &, double, double, int, int);

  Point coord(int, int) const;

  std::vector<std::vector<int>> _pixels;
private:
  const Point _center;
  const double _width;
  const double _height;
  const int _horPixels;
  const int _vertPixels;

};

#endif // CANVAS_HH