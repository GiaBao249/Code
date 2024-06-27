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

map<ll, ll> mp;
void Find()
{
    for (ll i = 1; i <= 10000; i++)
    {
        mp[i * i * i] = 1;
    }
}

void Solve()
{
    ll n;
    cin >> n;
    bool ok = false;
    for (ll i = 1; i <= 10000; i++)
    {

        if (mp[n - i * i * i] == 1)
        {
            ok = true;
            break;
        }
    }
    if (ok)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Find();
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}