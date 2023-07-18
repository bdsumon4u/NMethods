#include <bits/stdc++.h>

using namespace std;

class Secant
{
public:
    double xPrev, x, xNext, precision;
    Secant(double precision)
    {
        this->precision = precision;
        x = rand() % 10;
        xPrev = x - 9;
    }

    double fx(double x)
    {
        return 3 * x - cos(x) - 1;
        return pow(x, 2) - 4;
    }
    double findRoot()
    {
        while (true)
        {
            xNext = x - fx(x) * (x-xPrev) / (fx(x)-fx(xPrev));
            xPrev = x;
            x = xNext;
            if (abs(x - xPrev) < precision)
                break;
        }
        return xNext;
    }
};

int main()
{
    Secant solver(0.001);
    cout << solver.findRoot() << endl;
}