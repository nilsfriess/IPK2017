#include "canvas.hh"

#include <iostream>
#include <cmath>
#include <vector>

#include "pgm.hh"

double f(double x, double y);

int main() {
    int pixelWidth = 300, pixelHeight = 200;

    Canvas c = Canvas(Point(0, 0), 4, 3, pixelWidth, pixelHeight);

    c.fill([](int x, int y) -> double {
        if (x == 0 || y == 0) return 0;
        return std::sin(1.0 / x) * std::sin(1.0 / y);
    }); 

    c.print();

    std::cout << std::endl;
    return 0;
}