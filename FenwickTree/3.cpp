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
#define inf LLONG_MAX
const ll maxn = 1e6 + 5;
const ll MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \>
*/
struct Node {
    char c;
    ll u, v;
};
vector<ll> bit(maxn), a(maxn), mp;
ll n, q;
vector<Node> query;
void update(ll i, ll v)
{
    for(; i < maxn ; i += i & -i) {
        bit[i] += v;
    }
}

ll get(ll i)
{
    ll res = 0;
    for(; i > 0 ; i -= i & -i)
        res += bit[i];
    return res;
}

int cmp(int x)
{
    return lower_bound(all(mp) , x) - mp.begin() + 1;
}

void Solve()
{
    cin >> n >> q;
    a.resize(n + 1);
    f1(i, n) {
        cin >> a[i];
        mp.push_back(a[i]);
    }
    while(q--) {
        char c;
        cin >> c;
        if(c == '!') {
            ll p, k;
            cin >> p >> k;
            query.push_back({c, p, k});
            mp.push_back(p);
            mp.push_back(k);
        } else {
            ll l, r;
            cin >> l >> r;
            query.push_back({c, l, r});
            mp.push_back(l), mp.push_back(r);
        }
    }
    sort(all(mp));
    mp.erase(unique(all(mp)), mp.end());
    f1(i, n) {
        update(cmp(a[i]), 1);
    }
    for(auto &x : query) {
        if(x.c == '!') {
            update(cmp(a[x.u]), -1);
            a[x.u] = x.v;
            update(cmp(a[x.u]), 1);
        } else {
            cout << get(cmp(x.v)) - get(cmp(x.u) - 1) << el;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    Solve();
    return 0;
}
