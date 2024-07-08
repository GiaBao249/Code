#include <bits/stdc++.h>
using namespace std;
#define ll long long
// No Pain No Gain!

void Solve()
{
    int n;
    cin >> n;
    if (n == 3)
        cout << "NO" << endl;
    else if (n % 2 == 0)
    {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
            if (i % 2 == 0)
                cout << -1 << " ";
            else
                cout << 1 << " ";
    }
    else
    {
        cout << "YES" << endl;
        int x = n / 2 - 1;
        int y = -n / 2;
        for (int i = 0; i < n; i++)
            if (i % 2 == 0)
                cout << x << " ";
            else
                cout << y << " ";
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}
