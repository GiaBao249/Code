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
    ll a, b, n;
    cin >> a >> b >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    ll cnt = b;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        if (v[i] >= a)
            v[i] = a - 1;
        cnt += v[i];
    }
    cout << cnt << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}