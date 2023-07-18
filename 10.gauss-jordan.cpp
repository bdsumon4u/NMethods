#include <bits/stdc++.h>

using namespace std;

class GaussJordan
{
public:
    int n;
    vector<vector<double>> a;
    GaussJordan(int n)
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

    void solve()
    {
        // Jordan
        for (int i = 0; i < n; i++)
        {
            if (!a[i][i])
            {
                cout << "Infine Solution" << endl;
                exit(1);
            }
            for (int j = 0; j < n; j++)
            {
                if (i==j)
                    continue;
                double ratio = a[j][i] / a[i][i];
                for (int k = 0; k < n + 1; k++)
                {
                    a[j][k] -= ratio * a[i][k];
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << a[i][n]/a[i][i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    GaussJordan solver(3);
    solver.solve();

    return 0;
}