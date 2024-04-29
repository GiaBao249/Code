#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[100][100];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
                cin >> a[i][j];
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < 3; j++)
            {
                if (a[i][j] == 1)
                    cnt++;
            }
            if (cnt >= 2)
                res++;
        }
        cout << res;
    }
}