#include <bits/stdc++.h>

using namespace std;

class NewtonRaphson {
    public:
        double x, xNext, precision;
        NewtonRaphson(double precision) {
            this->precision = precision;
            x = rand() % 10;
        }

        double fx(double x) {
            return pow(x, 2) - 4;
        }
        double dfx(double x) {
            return 2 * x;
        }

        double findRoot() {
            while (true)
            {
                x = xNext;
                xNext = x - fx(x) / dfx(x);
                if (abs(x-xNext) < precision)
                    break;
            }
            return xNext;
        }
};

int main() {
        NewtonRaphson solver(0.001);
        cout << solver.findRoot() << endl;
}