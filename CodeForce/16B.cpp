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

void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> v;
    ll res = 0;
    int x = m;
    while (x--)
    {
        int a, b;
        cin >> a >> b;
        v.emplace_back(b, a);
    }
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < v.size(); i++)
    {
        if (n >= v[i].second)
        {
            res += v[i].second * v[i].first;
            n -= v[i].second;
        }
        else
        {
            res += n * v[i].first;
            break;
        }
    }
    cout << res << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}