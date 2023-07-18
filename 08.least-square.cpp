#include <bits/stdc++.h>

using namespace std;

class LeastSquare
{
public:
    vector<double> x_vals, y_vals;
    LeastSquare(vector<double> &x_vals, vector<double> &y_vals)
    {
        this->x_vals = x_vals;
        this->y_vals = y_vals;
    }

    void fit()
    {
        //
    }
};

int main()
{
    vector<double> x_values = {0, 1, 2, 3, 4};
    vector<double> y_values = {1, 3, 5, 7, 9};

    LeastSquare fitter(x_values, y_values);
    fitter.fit();
}