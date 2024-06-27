#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <limits>
using namespace std;
#define ll long long
// No Pain No Gain!

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return (a / gcd(a, b) * b);
}

void Solve()
{
    string s, t;
    cin >> s >> t;
    ll k = lcm(s.size(), t.size());
    string x = s;
    string y = t;
    while (x.size() < k)
        x += s;
    while (y.size() < k)
        y += t;
    if (x == y)
        cout << x << endl;
    else
        cout << -1 << endl;
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