#include <bits/stdc++.h>
using namespace std;
#define ll long long
// Code đi đừng sợ!

void Solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int x = 0;
    for (char c : s)
    {
        if (c == '1')
            x++;
    }
    if (x & 1)
    {
        cout << "NO" << endl;
        return;
    }
    int maxx = -1, minn = n;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            maxx = max(maxx, i);
            minn = min(minn, i);
        }
    }
    if (x == 2 && maxx - minn == 1)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
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