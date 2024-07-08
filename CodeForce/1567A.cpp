#include <bits/stdc++.h>
using namespace std;
#define ll long long
// No Pain No Gain!

void Solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string res;
    for (char c : s)
    {
        if (c == 'U')
            res.push_back('D');
        else if (c == 'D')
            res.push_back('U');
        else
            res.push_back(c);
    }
    cout << res << endl;
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