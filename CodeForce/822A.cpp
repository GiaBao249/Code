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
#include <math.h>
using namespace std;
#define ll long long
// No Pain No Gain!
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll Gt(ll n)
{
    if (n == 1)
        return 1;
    return n * Gt(n - 1);
}

void Solve()
{
    ll a, b;
    cin >> a >> b;
    ll s = 1;
    for (int i = 1; i <= min(a, b); i++)
    {
        s *= i;
    }
    cout << s << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}