#ifndef POINT_HH
#define POINT_HH


class Point {

public:
    Point() = default;
    Point(double, double);

    double x() const { return _x; }
    double y() const { return _y; }  

private:
    double _x = 0;
    double _y = 0;

};

#endif // POINT_HH