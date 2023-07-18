#include <bits/stdc++.h>

using namespace std;

class GaussElimination {
    public:
        int n;
        vector<vector<double>> a;
        GaussElimination(int n)
        {
            // cout << "Enter [A:H]" << endl;
            this->n = n;
            a.resize(n);
            for (int i = 0; i < n; i++)
            {
                a[i].resize(n + 1);
                for (int j = 0; j < n + 1; j++)
                {
                    cin >> a[i][j];
                }
            }
        }

        void solve() {

            // Elimination
            for (int i = 0; i < n-1; i++)
            {
                if (! a[i][i]) {
                    cout << "Infine Solution" << endl;
                    exit(1);
                }
                for (int j = i+1; j < n; j++)
                {
                    double ratio = a[j][i] / a[i][i];
                    for (int k = 0; k < n + 1; k++)
                    {
                        a[j][k] -= ratio * a[i][k];
                    }
                }
                
            }

            // substitution
            for (int i = n - 1; i >= 0; i--)
            {
                for (int j = i + 1; j < n; j++)
                {
                    a[i][n] -= a[i][j] * a[j][n];
                }
                a[i][n] /= a[i][i];
            }

            // Print
            for (int i = 0; i < n; i++)
            {
                cout << a[i][n] << " ";
            }
            cout << endl;
        }
};

int main() {
    GaussElimination solver(3);
    solver.solve();

    return 0;
}