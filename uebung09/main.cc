#include <iostream>

template <typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 1;
    int b = 2;
    std::cout << "a = " << a << " b = " << b << std::endl;
    swap(a, b);
    std::cout << "a = " << a << " b = " << b << std::endl;
    double c = 3;
    double d = 4;
    std::cout << "c = " << c << " d = " << d << std::endl;
    swap(c, d);
    std::cout << "c = " << c << " d = " << d << std::endl;

    // swap(a,c);
    return 0;
}