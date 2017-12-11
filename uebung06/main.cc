#include "canvas.hh"

#include <iostream>
#include <cmath>
#include <vector>

#include "pgm.hh"

double f(double x, double y);

int main() {
    int pixelWidth = 4000, pixelHeight = 3000;

    Canvas c = Canvas(Point(0, 0), 4, 3, pixelWidth, pixelHeight);

    c.fill([](int x, int y) -> double {
        if (x == 0 || y == 0) return 0;

        double ret = (std::sin(1.0/x) * std::sin(1.0/y));
        if (ret < 0)
            return 0;
        return ret;
    }); 


    bool pngSuccess = c.writePng("/home/nils/testPng.png");

    std::cout << pngSuccess << std::endl;
    return 0;
}