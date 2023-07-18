#include <bits/stdc++.h>

using namespace std;

class RegulaFalsi {
    public:
        double x0, x1, f0, f1, precision;
        RegulaFalsi(double precision) {
            this->precision = precision;
        }

        double fx(double x) {
            // return x * x * x - x * x + 2;
            return pow(x, 2) - 4;
            return 3 * x - cos(x) - 1;
        }

        bool guess() {
            srand(time(0));
            int r = rand()%10;
            for (int i = 0; i < 1e6; i++)
            {
                if (fx(r-9) * fx(r) < 0) {
                    x0 = r-9;
                    f0 = fx(x0);
                    x1 = r;
                    f1 = fx(x1);
                    return true;
                }
            }
            return false;
        }

        double findRoot() {
            if (! guess()) {
                cout << "Can't guess interval for the function." << endl;
                exit(1);
            }

            double x, f;
            do {
                x = (x0 * f1 - x1 * f0) / (f1 - f0);
                f = fx(x);

                if (f0 * f < 0) {
                    x1 = x;
                    f1 = f;
                } else {
                    x0 = x;
                    f0 = f;
                }
            } while (abs(f) >= precision);

            return x;
        }
};

int main() {
    RegulaFalsi solver(0.001);
    cout << solver.findRoot() << endl;
}