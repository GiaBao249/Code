#include <bits/stdc++.h>
using namespace std;
#define ll long long
using pii = pair<ll,ll>;
#define pb push_back
#define CLR(a , b) memset((a),b,sizeof(a))
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rep(i, a, b) for (int i = a; i <= b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define el '\n'
#define inf LONG_MAX
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

void file()
{
    if (fopen("Task.inp", "r")) {
        freopen("Task.inp", "r", stdin);
        freopen("Task.out", "w", stdout);
    }
}

int n, k;
vector<int> a;
vector<ll> res;
multiset<ll> u, v;

void Solve()
{
    cin >> n >> k;
    a.resize(n);
    res.resize(n - k + 1);
    f0(i, n) cin >> a[i];
    ll s = 0, t = 0;
    for (int i = 0; i < k; i++) {
        if (sz(u) && a[i] < *u.rbegin()) {
            u.insert(a[i]);
            s += a[i];
        } else {
            v.insert(a[i]);
            t += a[i];
        }
        if (sz(u) > (k + 1) / 2) {
            auto x = u.rbegin();
            v.insert(*x);
            s -= *x;
            t += *x;
            u.erase(prev(u.end()));
        }
        if (sz(v) > k / 2) {
            auto x = v.begin();
            u.insert(*x);
            s += *x;
            t -= *x;
            v.erase(x);
        }
    }
    ll med = *u.rbegin();
    res[0] = sz(u) * med - s + t - med * sz(v);
    for (int i = k; i < n; i++) {
        if (u.count(a[i - k])) {
            u.erase(u.find(a[i - k]));
            s -= a[i - k];
        } else {
            v.erase(v.find(a[i - k]));
            t -= a[i - k];
        }
        if (sz(u) && a[i] < *u.rbegin()) {
            u.insert(a[i]);
            s += a[i];
        } else {
            v.insert(a[i]);
            t += a[i];
        }
        while (sz(u) < (k + 1) / 2) {
            auto x = v.begin();
            u.insert(*x);
            t -= *x;
            s += *x;
            v.erase(x);
        }
        while (sz(u) > (k + 1) / 2) {
            auto x = u.rbegin();
            v.insert(*x);
            s -= *x;
            t += *x;
            u.erase(prev(u.end()));
        }
        med = *u.rbegin();
        res[i - k + 1] = sz(u) * med - s + t - med * sz(v);
    }
    for (int i = 0; i < n - k + 1; i++)
        cout << res[i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}
