#include <bits/stdc++.h>
using namespace std;
#define ll long long

map<ll, ll> mp;
ll res = 0, n;
ll a[2000001];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] %= 23;
    }
    for (int i = 1; i <= n; i++)
    {
        if (i > 6)
        {
            mp[a[i - 6]]++;
        }
        res += mp[a[i]];
    }
    cout << res << endl;
}