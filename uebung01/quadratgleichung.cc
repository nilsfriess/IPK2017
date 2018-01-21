#include <iostream>
#include <utility>
#include <cmath>

using namespace std;

pair<double, double> mitternachtsformel(double a, double b, double c);

int main()
{
    double a, b, c;

    do
    {
        cout << "a = ";
        cin >> a;
    } while (a == 0);
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;

    pair<double, double> nullstellen = mitternachtsformel(a, b, c);

    //check if NaN
    if (nullstellen.first == nullstellen.second)
    {
        cout << "Nullstelle = " << nullstellen.first;
    }
    else
    {
        if (nullstellen.first != nullstellen.first)
        {
            if (nullstellen.second != nullstellen.second)
            {
                cout << "Keine reelen Nullstellen";
            }
            else
            {
                cout << "Nullstelle = " << nullstellen.second;
            }
        }
        else
        {
            if (nullstellen.second != nullstellen.second)
            {
                cout << "Nullstelle = " << nullstellen.first;
            }
            else
            {
                cout << "Nullstellen = " << nullstellen.first << ", " << nullstellen.second;
            }
        }
    }

    cout << endl;

    return 0;
}

pair<double, double> mitternachtsformel(double a, double b, double c)
{
    double x1, x2;
    double root = sqrt(b * b - 4 * a * c);

    x1 = (-b + root) / (2 * a);
    x2 = (-b - root) / (2 * a);

    return make_pair(x1, x2);
}
