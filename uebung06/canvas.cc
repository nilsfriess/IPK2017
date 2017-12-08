
#include "canvas.hh"
#include "point.hh"

Canvas::Canvas(const Point& center, double width, double height, int horPixels, int vertPixels)
    :_center(center), _width(width), _height(height), _horPixels(horPixels), _vertPixels(vertPixels)
{}

Point Canvas::coord(int i, int j) const {
    if (i<=0 || i>=_horPixels || j<=0 || j>=_vertPixels)
        return Point();

    Point bottomLeft(
          _center.x() - 0.5 * _width
        , _center.y() - 0.5 * _height
    );
    
    double x = bottomLeft.x() + i * ( _width / ( _horPixels - 1 ) );
    double y = bottomLeft.y() + j * ( _height / ( _vertPixels - 1) );

    return Point(x, y);
}
