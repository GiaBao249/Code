#include <bits/stdc++.h>
using namespace std;
#define ll long long
// No Pain No Gain!

void Solve()
{
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    ll sum = a + b + c + d + e;
    if (sum % 5 == 0 && sum >= 5)
        cout << sum / 5 << endl;
    else
        cout << -1 << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}