#include <bits/stdc++.h>
using namespace std;
#define ll long long
// No Pain No Gain!

void Solve()
{
    ll a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;
    if (a + b - x - y <= n)
    {
        cout << x * y << endl;
        return;
    }
    ll a1 = a, b1 = b, n1 = n;
    ll a2 = a, b2 = b, n2 = n;

    ll com1 = 0, com2 = 0;
    ll x1 = min(a1 - x, n1);
    a1 -= x1;
    n1 -= x1;
    ll x2 = min(b1 - y, n1);
    b1 -= x2;
    com1 = a1 * b1;

    ll x3 = min(b2 - y, n2);
    b2 -= x3;
    n2 -= x3;
    ll x4 = min(a2 - x, n2);
    a2 -= x4;
    com2 = a2 * b2;

    cout << min(com1, com2) << endl;
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