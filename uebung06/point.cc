
#include "point.hh"

Point::Point(double x, double y)
    :_x(x), _y(y)
{}


bool Point::operator==(const Point &other) {
  return 
    (this->_x == other.x() ) &&
    (this->_y == other.y() ); 
}