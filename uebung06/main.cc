#include "canvas.hh"

#include <iostream>
#include <cmath>
#include <vector>

#include "pgm.hh"

double f(double x, double y);

int main() {
    int pixelWidth = 8000, pixelHeight = 4500;

    Canvas c = Canvas(Point(0, 0), 4, 3, pixelWidth, pixelHeight);

    for ( unsigned int i = 0 ; i < c._pixels.size() ; i++ )
        c._pixels[i].resize(pixelHeight);

    for (unsigned i=0; i<c._pixels.size(); i++) {
        for (unsigned j=0; j<c._pixels[i].size(); j++) {
            Point coordPoint = c.coord(i, j);
            c._pixels[i][j] = (int)f(coordPoint.x(), coordPoint.y());
            // std::cout << i << ", " << j << "\n";
        }
    }

    write_pgm(c._pixels, "/home/nils/test.pgm");

    std::cout << std::endl;
    return 0;
}

double f(double x, double y) {
    if (x == 0 || y == 0) return 0;
    double ret = 100 * (std::sin(1.0 / x) * std::sin(1.0 / y) + 1);

    //std::cout << ret << std::endl;  

    if (0 >= ret) return 0;

    return ret;
}

// double centerX = c._center.x();
//     double centerY = c._center.y();
//     double width = c._width;
//     double height = c._height;
//     double vert = c._vertPixels;
//     double hort = c._horPixels;

//     Point p = c.coord(0, 2);
//     Point t = Point(centerX - 0.5 * width, centerY + 0.5 * height);

//     bool e = p == t;

//     std::cout << p.x() << ", " << p.y() << "\n" << 
//                  t.x() << ", " << t.y() << "\n" << e;
