#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Bisection
{
public:
    double a, b, precision;
    Bisection(double precision)
    {
        this->precision = precision;
    }

    double fx(double x);

    bool guess()
    {
        srand(time(0));

        for (int i = 0; i < 1000; i++)
        {
            int r = rand() % 10;
            if (fx(r - 9) * fx(r) < 0)
            {
                this->a = r - 9;
                this->b = r;
                return true;
            }
        }

        return false;
    }

    double findRoot()
    {
        if (!guess())
        {
            cout << "Can't guess an interval for the given function." << endl;
            exit(1);
        }

        while (abs(b-a) >= precision)
        {
            double c = (a + b) / 2;

            if (abs(fx(c)) < precision)
                return c;

            if (fx(a) * fx(c) < 0)
                b = c;
            else if (fx(a) * fx(c) > 0)
                a = c;
            else {
                cout << "Ooo" << endl;
            }
        }

        return (a + b) / 2;
    }
};

double Bisection::fx(double x)
{
    return pow(x, 2) - 4;
    return 3 * x - cos(x) - 1;
}

int main()
{
    Bisection solver(0.001);
    cout << solver.findRoot() << endl;

    return 0;
}
