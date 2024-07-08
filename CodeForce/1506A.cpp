#include <bits/stdc++.h>
using namespace std;
#define ll long long
// No Pain No Gain!

void Solve()
{
    ll n, m, x;
    cin >> n >> m >> x;
    x--;
    ll c = x / n;
    ll r = x % n;
    cout << r * m + c + 1 << endl;
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