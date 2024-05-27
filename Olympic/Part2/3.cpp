#include <bits/stdc++.h>
using namespace std;

int n, m;
int X[100];

int Try(int i)
{
    for (int j = X[i - 1] + 1; j <= n - m + i; j++)
    {
        X[i] = j;
        if (i == m)
        {
            for (int l = 1; l <= m; l++)
                cout << X[l];
            cout << endl;
        }
        else
            Try(i + 1);
    }
}

int main()
{
    cin >> n >> m;
    memset(X, 0, sizeof(X));
    Try(1);
}