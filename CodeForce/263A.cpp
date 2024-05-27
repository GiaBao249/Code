#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int a[5][5];
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 1)
            {
                x = i;
                y = j;
            }
        }
    int res = abs(x - 2) + abs(y - 2);
    cout << res << endl;
}
