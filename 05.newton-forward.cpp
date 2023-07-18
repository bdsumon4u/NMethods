#include <bits/stdc++.h>

using namespace std;

class NewtonForward {
    public:
        vector<double> x_vals, y_vals;
        vector<vector<double>> table;
        NewtonForward(vector<double> &x_vals, vector<double> &y_vals)
        {
            this->x_vals = x_vals;
            this->y_vals = y_vals;
            buildDifferenceTable();
        }

        void buildDifferenceTable() {
            int n = x_vals.size();
            table.resize(n, vector<double>(n, 0));
            for (int i = 0; i < n; i++)
            {
                table[i][0] = y_vals[i];
            }

            // Forward
            for (int j = 1; j < n; j++)
            {
                for (int i = 0; i < n-j; i++)
                {
                    table[i][j] = table[i + 1][j - 1] - table[i][j - 1];
                }
            }
        }

        double interpolate(double x) {
            int n = x_vals.size();
            double h = x_vals[1] - x_vals[0];
            double p = (x - x_vals[0]) / h;
            double result = y_vals[0];
            double term = 1.0;
            for (int i = 1; i < n; i++)
            {
                term *= (p - (i - 1)) / i;
                result += term * table[0][i];
            }
            return result;
        }
};

int main()
{
    vector<double> x_values = {0, 1, 2, 3, 4};
    vector<double> y_values = {1, 3, 5, 7, 9};

    NewtonForward interpolator(x_values, y_values);
    cout << interpolator.interpolate(2.5) << endl;
}