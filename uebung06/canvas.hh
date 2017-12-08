#ifndef CANVAS_HH
#define CANVAS_HH

#include <vector>
#include "point.hh"

class Canvas {
public:
    Canvas(const Point&, double, double, int, int);

    Point coord(int, int) const;

private:
    const Point _center;
    const double _width;
    const double _height;
    const int _horPixels;
    const int _vertPixels;

    std::vector<std::vector<double>> grayscale;
};

#endif // CANVAS_HH