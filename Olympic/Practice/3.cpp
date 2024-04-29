#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int x[100], n;

void sinhnhiphan(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        x[i] = j;
        if (i == n)
        {
            for (int k = 1; k <= n; k++)
                cout << x[k];
            cout << endl;
        }
        else
            sinhnhiphan(i + 1);
    }
}

int main()
{
    cin >> n;
    sinhnhiphan(1);
}