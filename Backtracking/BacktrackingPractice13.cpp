#include <bits/stdc++.h>
using namespace std;

int n = 8, x[100], hang[100], d1[100], d2[100], ans = 0;
int a[100][100];

void Try(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (hang[j] && d1[i - j + n] && d2[i + j - 1])
        {
            x[i] = j;
            hang[j] = d1[i - j + n] = d2[i + j - 1] = 0;
            if (i == n)
            {
                int sum = 0;
                for (int i = 1; i <= n; i++)
                {
                    sum += a[i][x[i]];
                }
                ans = max(ans, sum);
            }
            else
                Try(i + 1);
            hang[j] = d1[i - j + n] = d2[i + j - 1] = 1;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ans = 0;
        for (int i = 0; i < 100; i++)
        {
            hang[i] = d1[i] = d2[i] = true;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> a[i][j];
            }
        }
        Try(1);
        cout << ans << endl;
    }
}