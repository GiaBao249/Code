#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int x[100], n;

void Test(int i, int end)
{
    if (i == n)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << x[j];
        }
        cout << endl;
    }
    else
    {
        if (end == 1)
        {
            x[i] = 0;
            Test(i + 1, 0);
        }
        else
        {
            x[i] = 0;
            Test(i + 1, 0);
            x[i] = 1;
            Test(i + 1, 1);
        }
    }
}

int main()
{
    cin >> n;
    Test(1, 0);
}