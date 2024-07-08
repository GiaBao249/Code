#include <bits/stdc++.h>
using namespace std;
#define ll long long
// No Pain No Gain!

void Solve()
{
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    int cnt = 0;
    for (int i = n - cnt - 1, j = m - cnt - 1; i >= 0, j >= 0; i--, j--)
    {
        if (s[i] == t[j])
            cnt++;
        else
            break;
    }
    cout << n + m - 2 * cnt << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}
