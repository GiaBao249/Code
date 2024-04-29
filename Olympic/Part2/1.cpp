#include <bits/stdc++.h>
using namespace std;

int n;
int X[100];
int Try(int i)
{
    for (int j = 1; j <= n; j++)
    {
        X[i] = j;
        if (i == n)
        {
            for (int i = 1; i <= n; i++)
                cout << X[i];
            cout << endl;
        }
        else
            Try(i + 1);
    }
}

int main()
{
    cin >> n;
    Try(1);
}