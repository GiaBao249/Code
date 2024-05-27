#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n, s = 0;
    cin >> n;
    int a[n][n], ans[n] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] > ans[i])
                ans[i] = a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (ans[i] == n - 1 && s == 0)
        {
            ans[i] = n;
            s = 1;
        }
        cout << ans[i] << " ";
    }
    return 0;
}
