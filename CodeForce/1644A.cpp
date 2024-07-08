#include <bits/stdc++.h>
using namespace std;
#define ll long long
// No Pain No Gain!

void Solve()
{
    string s;
    cin >> s;
    int r = 0, g = 0, b = 0;
    bool ok = true;
    for (char c : s)
    {
        if (c == 'r')
            r++;
        else if (c == 'g')
            g++;
        else if (c == 'b')
            b++;
        else if (c == 'R')
        {
            if (r > 0)
                r--;
            else if (r <= 0)
            {
                ok = false;
                break;
            }
        }
        else if (c == 'G')
        {
            if (g > 0)
                g--;
            else if (g <= 0)
            {
                ok = false;
                break;
            }
        }
        else if (c == 'B')
        {
            if (b > 0)
                b--;
            else if (b <= 0)
            {
                ok = false;
                break;
            }
        }
    }
    if (ok)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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