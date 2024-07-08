#include <bits/stdc++.h>
using namespace std;
#define ll long long
// No Pain No Gain!

void Solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> v({a, b, c});
    sort(v.begin(), v.end());
    a = v[0];
    b = v[1];
    c = v[2];
    if (a + b == c || a == b && c % 2 == 0 || b == c && a % 2 == 0)
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