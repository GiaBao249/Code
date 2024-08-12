#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define endl '\n'
#define inf INT_MAX
const ll mod = 1000000007LL;
/*
 /\_/\
(= ._.)
/ >  \> https://codeforces.com/contest/1999/problem/F
*/

ll fact[200005], in_fact[200005];

ll Mul(ll a, ll b)
{
    ll res = 0;
    a = a % mod;
    while (b > 0)
    {
        if (b & 1)
            res = (res + a) % mod;
        b = b >> 1;
        a = (a << 1) % mod;
    }
    return res;
}

ll P(ll a, ll b)
{
    a = a % mod;
    ll res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = Mul(res, a);
        }
        b = b >> 1;
        a = Mul(a, a);
    }
    return res;
}

ll C(ll n, ll k)
{
    ll ret = fact[n];
    (ret *= in_fact[k]) %= mod;
    (ret *= in_fact[n - k]) %= mod;
    return ret;
}

void Run()
{
    fact[0] = 1, in_fact[0] = 1;
    for (int i = 1; i < 200001; i++)
    {
        fact[i] = (fact[i - 1] * (1LL * i)) % mod;
        in_fact[i] = P(fact[i], mod - 2);
    }
}

void Solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int c0 = 0, c1 = 0;
    f0(i, n)
    {
        cin >> a[i];
        if (a[i] == 1)
            c1++;
        else
            c0++;
    }
    ll res = 0;
    for (int i = (k + 1) / 2; i <= k; i++)
    {
        if (i <= c1 && k - i <= c0)
        {
            ll x = C(c1, i);
            (x *= C(c0, k - i)) %= mod;
            (res += x) %= mod;
        }
    }
    cout << res << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("input.txt", "r"))
    {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    Run();
    int t;
    cin >> t;
    while (t--)
        Solve();
    return 0;
}