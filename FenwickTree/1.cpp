#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (ll i = 0; i < n; i++)
#define f1(i, n) for (ll i = 1; i <= n; i++)
#define For(i, a, b) for (ll i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (ll)x.size()
#define el '\n'
#define inf ll_MAX
const ll maxn = 200005;
const ll MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \>https://codeforces.com/gym/458672/problem/A
*/
vector<ll> bit(maxn), a(maxn);
ll n, q;
void update(ll i, ll v)
{
    for(; i < maxn ; i += i & -i)
        bit[i] += v;
}

ll get(ll i)
{
    ll res = 0;
    for(; i > 0 ; i -= i & -i)
        res += bit[i];
    return res;
}

void Solve()
{
    cin >> n >> q;
    a.resize(n + 1, 0);
    bit.resize(n + 1, 0);
    f1(i,n) {
        cin >> a[i];
        update(i, a[i]);
    }
    while(q--) {
        ll t ;
        cin >> t;
        if(t == 1) {
            ll u,v ;
            cin >> u >> v;
            update(u,v - (get(u) - get(u - 1)));
        } else {
            ll x ;
            cin >> x;
            cout << get(x) << el;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}
