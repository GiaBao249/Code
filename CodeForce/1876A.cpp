#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, p;
        cin >> n >> p;
        vector<pair<ll, ll>> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i].first;
        for (int i = 0; i < n; i++)
            cin >> v[i].second;
        sort(v.begin(), v.end());

        ll a = n - 1, b = p;
        for (ll i = 0; i < n; i++)
        {
            if (v[i].second >= p)
                break;
            ll cnt = (a < v[i].first) ? a : v[i].first;
            b += cnt * v[i].second;
            a -= cnt;
        }
        b += a * p;
        cout << b << endl;
    }
}