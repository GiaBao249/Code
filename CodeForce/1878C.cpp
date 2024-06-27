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

void Solve()
{
    ll n, k, x;
    cin >> n >> k >> x;
    ll Sk = (k * (k + 1)) / 2;
    ll Sn = (n * (n + 1)) / 2;
    ll Sx = (n - k) * (n - k + 1) / 2;
    if (x >= Sk && x <= Sn - Sx)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}