#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define For(i, a, b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)x.size()
#define el '\n'
#define inf INT_MAX
const int maxn = 2e5+ 5;
const int MOD = 1e9 + 7;
/*
 /\_/\
(= >_<)
/ >  \>
*/
int n;
ll a[maxn], t[4 * maxn];
void update(int id, int l, int r, int p, ll v)
{
    if (p < l || p > r) return;
    if (l == r) {
        t[id] = v;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, p, v);
    update(id * 2 + 1, mid + 1, r, p, v);
    t[id] = t[id * 2] + t[id * 2 + 1];
}
int Bs(int id, int l, int r, int x)
{
    if (l == r)
        return l;
    int mid = (l + r) / 2;
    if (t[id * 2] >= x) return Bs(id * 2, l, mid, x);
    return Bs(id * 2 + 1, mid + 1, r, x - t[id * 2]);
}
void Solve()
{
    cin >> n;
    f1(i, n) {
        cin >> a[i];
        update(1, 1, n, i, 1);
    }
    f1(i, n) {
        int k ;
        cin >> k;
        auto x = Bs(1, 1, n,k);
        cout << a[x] << " ";
        update(1, 1, n, x, 0);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}
