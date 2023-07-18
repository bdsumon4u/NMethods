#include <bits/stdc++.h>

using namespace std;

class LagrangeFormula
{
public:
    vector<double> x_vals, y_vals;
    vector<vector<double>> table;
    LagrangeFormula(vector<double> &x_vals, vector<double> &y_vals)
    {
        this->x_vals = x_vals;
        this->y_vals = y_vals;
    }

    double interpolate(double x)
    {
        double result = 0;
        for (int i = 0; i < x_vals.size(); i++)
        {
            double term = 1;
            for (int j = 0; j < x_vals.size(); j++)
            {
                if (i == j)
                    continue;
                term *= (x - x_vals[j]) / (x_vals[i] - x_vals[j]);
            }
            result += term*y_vals[i];
        }
        return result;
    }
};

int main()
{
    vector<double> x_values = {0, 1, 2, 3, 4};
    vector<double> y_values = {1, 3, 5, 7, 9};

    LagrangeFormula interpolator(x_values, y_values);
    cout << interpolator.interpolate(0.5) << endl;
}